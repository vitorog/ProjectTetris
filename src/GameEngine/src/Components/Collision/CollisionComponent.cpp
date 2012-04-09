/*
 * CollisionComponent.cpp
 *
 *  Created on: 11/03/2012
 *      Author: Vitor
 */

#include "CollisionComponent.h"

#include "GameObjects/GameObject.h"

CollisionComponent::CollisionComponent(ObjectFrame *frame, float width, float height){
	m_bbox_width = width;
	m_bbox_height = height;
	m_obj_frame = frame;
	m_bounding_box.setBoundaries(frame->getCenter(), m_bbox_width, m_bbox_height);
}

CollisionComponent::~CollisionComponent() {
	// TODO Auto-generated destructor stub
}


bool CollisionComponent::checkCollision(GameObject* object) {
	CollisionComponent* compare_collision_cmp = dynamic_cast<CollisionComponent*>(object->getComponent(COLLISION_COMPONENT));
	if(compare_collision_cmp != nullptr){
		BoundingBox2d* compare_bbox = compare_collision_cmp->getBoundingBox();
		if(compare_bbox != nullptr){
			if(m_bounding_box.isPointInside(compare_bbox->getCenter())){
				return true;
			}else{
				for(int i = 0; i < 4; i++){
					if(m_bounding_box.isPointInside(compare_bbox->getBorderPoint(i))){
						return true;
					}
				}
			}
		}
	}
	return false;
}

void CollisionComponent::updateBoundingBox(){
	m_bounding_box.setBoundaries(m_obj_frame->getCenter(), m_bbox_width, m_bbox_height);
}

BoundingBox2d* CollisionComponent::getBoundingBox() {
	return &m_bounding_box;
}

void CollisionComponent::resizeBoundingBox(float width, float height)
{
	m_bbox_width = width;
	m_bbox_height = height;
	updateBoundingBox();
}










