/*
 * GameObject.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#include "GameObject.h"

#include <iostream>

#include "../Components/CollisionComponent.h"


int GameObject::m_id = 0;

GameObject::GameObject() {
	m_id++;
}

GameObject::~GameObject() {
	//Delete children
	std::list<GameObject*>::iterator children_it;
	GameObject* curr_obj = nullptr;
	for(children_it = m_children.begin(); children_it != m_children.end(); children_it++){
		curr_obj = (*children_it);
		children_it = m_children.erase(children_it);
		delete curr_obj;
	}

	//Delete components
	std::map<ComponentType, GameObjComponent*>::iterator component_it;
	GameObjComponent* curr_component = nullptr;
	for(component_it = m_components.begin(); component_it != m_components.end(); component_it++){
		curr_component = (*component_it).second;
		m_components.erase(component_it);
		delete curr_component;
	}
}

void GameObject::addComponent(GameObjComponent* component) {
	if(RendererComponent* renderer = dynamic_cast<RendererComponent*>(component)){
		m_components[RENDERER_COMPONENT] = renderer;
	}
	if(MeshComponent* mesh = dynamic_cast<MeshComponent*>(component)){
		m_components[MESH_COMPONENT] = mesh;
	}
	if(MaterialComponent* material = dynamic_cast<MaterialComponent*>(component)){
		m_components[MATERIAL_COMPONENT] = material;
	}
	if(CollisionComponent* collision = dynamic_cast<CollisionComponent*>(component)){
		m_components[COLLISION_COMPONENT] = collision;
	}

}

void GameObject::addChild(GameObject* obj) {
	m_children.push_back(obj);
}

GameObjComponent* GameObject::getComponent(ComponentType type) {
	if(m_components.find(type) != m_components.end()){
		return m_components[type];
	}
	return nullptr;
}

void GameObject::render() {
	glPushMatrix();
	glMultMatrixf(glm::value_ptr(m_frame.getTransformationMatrix()));
	if(m_components.find(RENDERER_COMPONENT) != m_components.end()){
		RendererComponent* renderer_cmp = dynamic_cast<RendererComponent*>(m_components[RENDERER_COMPONENT]);
		if(m_components.find(MESH_COMPONENT) != m_components.end()){
			MeshComponent* mesh_cmp = dynamic_cast<MeshComponent*>(m_components[MESH_COMPONENT]);
			if(m_components.find(MATERIAL_COMPONENT) != m_components.end()){
				MaterialComponent* material_cmp = dynamic_cast<MaterialComponent*>(m_components[MATERIAL_COMPONENT]);
				renderer_cmp->render(this->m_frame,mesh_cmp, material_cmp);
			}
			renderer_cmp->render(this->m_frame,mesh_cmp);
		}
	}
	glPopMatrix();

	if(hasChildren()){
		std::list<GameObject*>::iterator it;
		for(it = m_children.begin(); it != m_children.end(); it++){
			(*it)->render();
		}
	}
}

bool GameObject::hasChildren() {
	return (m_children.size() != 0) ? true : false;
}

int GameObject::getId() {
	return m_id;
}

std::list<GameObject*>* GameObject::getChildren() {
	return &m_children;
}

ObjectFrame& GameObject::getFrame() {
	return m_frame;
}

void GameObject::applyTransformMatrix() {
	CollisionComponent* collision_cmp = nullptr;
	std::list<GameObject*>::iterator it;
	GameObject* curr_obj = nullptr;
	for(it = m_children.begin(); it != m_children.end(); it++)
	{
		curr_obj = (*it);
		if(curr_obj != nullptr){
			curr_obj->getFrame().applyTransformation(this->getFrame().getTransformationMatrix());
			collision_cmp = dynamic_cast<CollisionComponent*>(curr_obj->getComponent(COLLISION_COMPONENT));
			if(collision_cmp != nullptr){
				collision_cmp->updateBoundingBox();
			}

		}
	}
}










