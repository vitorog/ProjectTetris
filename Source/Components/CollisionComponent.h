/*
 * CollisionComponent.h
 *
 *  Created on: 11/03/2012
 *      Author: Vitor
 */

#ifndef COLLISIONCOMPONENT_H_
#define COLLISIONCOMPONENT_H_

#include "GameObjComponent.h"
#include "../ObjectFrame.h"

class BoundingBox2D
{
public:
	BoundingBox2D(glm::vec3 position, float size){
		m_center = position;
		m_size = size;
		updateBoundaries();
	}
	void updateBoundaries()
	{
		glm::vec3 lower_left;
		glm::vec3 upper_left;
		glm::vec3 lower_right;
		glm::vec3 upper_right;

		float half_size = m_size/2;
		lower_left = glm::vec3(m_center + glm::vec3(-half_size,-half_size,0));
		lower_right = glm::vec3(m_center + glm::vec3(half_size,-half_size,0));
		upper_left = glm::vec3(m_center + glm::vec3(-half_size,+half_size,0));
		upper_right = glm::vec3(m_center + glm::vec3(half_size,half_size,0));

		m_boundaries[0] = lower_left;
		m_boundaries[1] = lower_right;
		m_boundaries[2] = upper_right;
		m_boundaries[3] =  upper_left;
	}
	glm::vec3 m_center;
	glm::vec3 m_boundaries[4];
	float m_size;
};

class CollisionComponent : public GameObjComponent {
public:
	CollisionComponent(glm::vec3 position);
	virtual ~CollisionComponent();
	BoundingBox2D m_collision_box;
};

#endif /* COLLISIONCOMPONENT_H_ */
