/*
 * GameObject.h
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "../Components/GameObjComponent.h"
#include "../Components/RendererComponent.h"

#include <list>
#include <map>

#include "../ObjectFrame.h"


class GameObject {
public:
	GameObject();
	virtual ~GameObject();
	void addComponent(GameObjComponent* component);
	void addChild(GameObject* obj);
	void render();
	GameObjComponent* get_component(ComponentType type);
	bool has_children();

protected:
	std::list<GameObject*> m_children;
	std::map<ComponentType, GameObjComponent*> m_components;
	ObjectFrame m_frame;
};

#endif /* GAMEOBJECT_H_ */
