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
#include "../Components/CollisionComponent.h"
#include "../ObjectFrame.h"

#include <list>
#include <map>

class GameObject {
public:
	GameObject();
	virtual ~GameObject();
	void addComponent(GameObjComponent* component);
	void addChild(GameObject* obj);
	std::list<GameObject*>* getChildren();
	void render();
	GameObjComponent* getComponent(ComponentType type);
	bool hasChildren();
	int getId();
	ObjectFrame& getFrame();
	void applyTransformMatrix();
	void setPosition(glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f));
	void move(float x, float y);
	void rotate(float angle, glm::vec3 axis);
	void clearChildren();
protected:
	std::list<GameObject*> m_children;
	std::map<ComponentType, GameObjComponent*> m_components;
	ObjectFrame m_frame;
	static int m_id;
};

#endif /* GAMEOBJECT_H_ */
