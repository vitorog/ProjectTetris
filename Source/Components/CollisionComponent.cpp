/*
 * CollisionComponent.cpp
 *
 *  Created on: 11/03/2012
 *      Author: Vitor
 */

#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(glm::vec3 position)
	: m_collision_box(position,1.0f)
{

}

CollisionComponent::~CollisionComponent() {
	// TODO Auto-generated destructor stub
}

