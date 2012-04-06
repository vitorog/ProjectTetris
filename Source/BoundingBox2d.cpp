/*
 * BoundingBox2d.cpp
 *
 *  Created on: 11/03/2012
 *      Author: Vitor
 */

#include "BoundingBox2d.h"

BoundingBox2d::~BoundingBox2d() {
}

void BoundingBox2d::setBoundaries(glm::vec3 center, float width, float height) {
	m_boundaries.clear();
	m_center = center;
	float half_width = width/2.0f;
	float half_height = height/2.0f;
	glm::vec3 lower_left = glm::vec3(center + glm::vec3(-half_width, -half_height, 0.0f));
	glm::vec3 lower_right = glm::vec3(center + glm::vec3(half_width, -half_height, 0.0f));
	glm::vec3 upper_right = glm::vec3(center + glm::vec3(half_width, half_height, 0.0f));
	glm::vec3 upper_left = glm::vec3(center + glm::vec3(-half_width, half_height, 0.0f));

	m_boundaries.push_back(lower_left);
	m_boundaries.push_back(lower_right);
	m_boundaries.push_back(upper_right);
	m_boundaries.push_back(upper_left);
}

bool BoundingBox2d::isPointInside(glm::vec3 point) {
	if( (point.x > m_boundaries[0].x) && (point.x < m_boundaries[2].x) )
	{
		if( (point.y > m_boundaries[0].y) && (point.y < m_boundaries[2].y ) ){
			return true;
		}
	}
	return false;
}

glm::vec3 BoundingBox2d::getCenter() {
	return m_center;
}

glm::vec3 BoundingBox2d::getBorderPoint(int pos) {
	return m_boundaries[pos];
}












