/*
 * GameObject.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#include "GameObject.h"

GameObject::GameObject() {

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

}

void GameObject::addChild(GameObject* obj) {
	m_children.push_back(obj);
}

GameObjComponent* GameObject::get_component(ComponentType type) {
	if(m_components.find(RENDERER_COMPONENT) != m_components.end()){
		return m_components[RENDERER_COMPONENT];
	}
	return nullptr;
}

void GameObject::render() {
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
	if(has_children()){
		std::list<GameObject*>::iterator it;
		for(it = m_children.begin(); it != m_children.end(); it++){
			(*it)->render();
		}
	}
}

bool GameObject::has_children() {
	return (m_children.size() != 0) ? true : false;
}







