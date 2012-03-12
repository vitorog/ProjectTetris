/*
 * CollisionComponent.h
 *
 *  Created on: 11/03/2012
 *      Author: Vitor
 */

#ifndef COLLISIONCOMPONENT_H_
#define COLLISIONCOMPONENT_H_

#include "GameObjComponent.h"
#include "../BoundingBox2d.h"

class BoundingBox2d;
class ObjectFrame;
class GameObject;

class CollisionComponent : public GameObjComponent {
public:
	CollisionComponent(ObjectFrame* frame);
	virtual ~CollisionComponent();
	bool checkCollision(GameObject* object);
	void updateBoundingBox();
	BoundingBox2d* getBoundingBox();
private:
	ObjectFrame* m_obj_frame;
	BoundingBox2d m_bounding_box;
};

#endif /* COLLISIONCOMPONENT_H_ */
