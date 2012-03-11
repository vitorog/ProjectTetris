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
	GameObject(int id = -1);
	virtual ~GameObject();
	void addComponent(GameObjComponent* component);
	void addChild(GameObject* obj);
	void render();
	GameObjComponent* get_component(ComponentType type);
	bool has_children();
	int getId();
	ObjectFrame& getFrame();
protected:
	std::list<GameObject*> m_children;
	std::map<ComponentType, GameObjComponent*> m_components;
	ObjectFrame m_frame;
	int m_id;
};

#endif /* GAMEOBJECT_H_ */
