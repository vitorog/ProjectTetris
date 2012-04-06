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
	CollisionComponent(ObjectFrame* frame, float width = 1.0f, float height = 1.0f);
	virtual ~CollisionComponent();
	bool checkCollision(GameObject* object);
	void updateBoundingBox();
	BoundingBox2d* getBoundingBox();
	void resizeBoundingBox(float width, float height);
private:
	ObjectFrame* m_obj_frame;
	BoundingBox2d m_bounding_box;
	float m_bbox_width;
	float m_bbox_height;
};

#endif /* COLLISIONCOMPONENT_H_ */
