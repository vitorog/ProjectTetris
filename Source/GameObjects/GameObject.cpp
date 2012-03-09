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
	std::list<GameObject*>::iterator it;
	GameObject* curr_obj = nullptr;
	for(it = m_children.begin(); it != m_children.end(); it++){
		curr_obj = (*it);
		it = m_children.erase(it);
		delete curr_obj;
	}

}

void GameObject::addComponent(GameObjComponent* component) {
	if(RendererComponent* renderer = dynamic_cast<RendererComponent*>(component)){
		m_components[RENDERER_COMPONENT] = renderer;
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
		renderer_cmp->render(m_center, 1.0f, m_color);
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

void Point3::operator=(const Point3& point) {
	this->x = point.x;
	this->y = point.y;
	this->z = point.z;
}





