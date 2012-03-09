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

}

void GameObject::render() {
	if(m_components.find(RENDERER_COMPONENT) != m_components.end()){
		RendererComponent* renderer_cmp = dynamic_cast<RendererComponent*>(m_components[RENDERER_COMPONENT]);
		renderer_cmp->render();
		if(has_children()){
			std::list<GameObject*>::iterator it;

			glPushMatrix();
			//glLoadIdentity();
			float aux = 0.0f;
			for(it = m_children.begin(); it != m_children.end(); it++){
				glScalef(0.95f,0.95f,1.0f);
				glColor3f(0.0f + aux,0.0f,0.0f);
				(*it)->render();
				aux+=0.1;
			}
			glPopMatrix();
			glColor3f(1.0f,1.0f,1.0f);
		}
	}
}

bool GameObject::has_children() {
	return (m_children.size() != 0) ? true : false;
}




