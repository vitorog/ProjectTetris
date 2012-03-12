/*
 * ObjectFrame.cpp
 *
 *  Created on: 09/03/2012
 *      Author: Vitor
 */

#include "ObjectFrame.h"

ObjectFrame::ObjectFrame() {
	m_transformation_matrix = glm::mat4();
}

void ObjectFrame::setCenter(glm::vec3 position) {
	m_center = glm::vec3();
	m_translate_vec = position - m_center;
	translate(m_translate_vec);
}

glm::vec3 ObjectFrame::getCenter() {
	return m_center;
}


glm::mat4x4& ObjectFrame::getTransformationMatrix() {
	return m_transformation_matrix;
}

void ObjectFrame::setTransformationMatrix(glm::mat4x4& transformation_matrix) {
	m_transformation_matrix = transformation_matrix;
	updateCenter();
}

void ObjectFrame::translate(glm::vec3 direction) {
	m_transformation_matrix = glm::translate(m_transformation_matrix,direction);
	updateCenter();

}

void ObjectFrame::rotate(float angle, glm::vec3 axis) {
	m_transformation_matrix = glm::rotate(m_transformation_matrix,angle,axis);
	updateCenter();
}

void ObjectFrame::applyTransformation(glm::mat4x4& transformation_matrix) {
	m_transformation_matrix = glm::mat4();
	m_transformation_matrix = m_transformation_matrix * transformation_matrix;
	m_transformation_matrix = glm::translate(m_transformation_matrix, m_translate_vec);
	updateCenter();
}

void ObjectFrame::updateCenter()
{
	m_center = glm::vec3();
	glm::vec4 aux_center = glm::vec4(m_center,1.0f);
	aux_center = m_transformation_matrix * aux_center;
	m_center.x = aux_center.x;
	m_center.y = aux_center.y;
	m_center.z = aux_center.z;
}



