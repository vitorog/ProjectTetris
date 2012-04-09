/*
 * ObjectFrame.cpp
 *
 *  Created on: 09/03/2012
 *      Author: Vitor
 */

#include "ObjectFrame.h"

#include <iostream>

ObjectFrame::ObjectFrame() {
	m_translation_matrix = glm::mat4();
	m_rotation_matrix = glm::mat4();
	m_transformation_matrix = glm::mat4();
	m_rotate_vec = glm::vec3(0.0f,0.0f,1.0f);
	m_last_angle = 0.0f;
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
	m_translation_matrix = glm::translate(m_translation_matrix,direction);
	updateTransformationMatrix();
	updateCenter();
}

void ObjectFrame::rotate(float angle, glm::vec3 axis) {
	m_rotate_vec = axis;
	m_last_angle += angle;

//	float sin_angle = sin((angle*PI)/180);
//	float cos_angle = cos((angle*PI)/180);
//	if(angle >= 0){
//		if(fabs(sin_angle) > 0.999999){
//			sin_angle = 1.0f;
//		}
//		if(fabs(cos_angle) < 0.000001){
//			cos_angle = 0.0f;
//		}
//	}
	float sin_angle;
	float cos_angle;
	switch((int)angle){
	case 0:
		sin_angle = 0.0f;
		cos_angle = 1.0f;
	break;
	case 90:
		sin_angle = 1.0f;
		cos_angle = 0.0f;
	break;
	case 180:
		sin_angle = 0.0f;
		cos_angle = -1.0f;
	break;
	case 270:
		sin_angle = -1.0f;
		cos_angle = 0.0f;
	break;
	case 360:
		sin_angle = 0.0f;
		cos_angle = 1.0f;
	break;
	default:
		sin_angle = sin((angle*PI)/180);
		cos_angle = cos((angle*PI)/180);
		if(fabs(sin_angle) > 0.999999){
			sin_angle = 1.0f;
		}
		if(fabs(cos_angle) < 0.000001){
			cos_angle = 0.0f;
		}
	break;
	}
//	std::cout << "Angle: " << angle << " Sin: " << sin_angle << " Cos: " << cos_angle << std::endl;
	glm::mat4 rotation_matrix =
			glm::mat4(glm::vec4(cos_angle,sin_angle,0.0f,0.0f),
					glm::vec4(-sin_angle,cos_angle,0.0f,0.0f),
					glm::vec4(0.0f,0.0f,1.0f,0.0f),
					glm::vec4(0.0f,0.0f,0.0f,1.0f)
	);
	m_rotation_matrix = m_rotation_matrix * rotation_matrix;
	updateTransformationMatrix();
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

void ObjectFrame::resetRotation()
{
	m_rotation_matrix = glm::mat4();
	m_last_angle = 0;
	updateTransformationMatrix();
	updateCenter();
}

void ObjectFrame::resetTranslation()
{
	m_translation_matrix = glm::mat4();
	updateTransformationMatrix();
	updateCenter();
}

void ObjectFrame::updateTransformationMatrix() {
	m_transformation_matrix = m_translation_matrix * m_rotation_matrix;
}

glm::mat4x4& ObjectFrame::getRotationMatrix() {
	return m_rotation_matrix;
}

glm::mat4x4& ObjectFrame::getTranslationMatrix() {
	return m_translation_matrix;
}

void ObjectFrame::printTransformationMatrix() {
	std::cout << "Matrix: " << std::endl;
	glm::vec4 row;
	for(int i = 0; i < 4; i++){
		row = m_transformation_matrix[i];
		std::cout << row.x << " " << row.y << " " << row.z << " " << row.w << std::endl;
	}
	std::cout << "End matrix" << std::endl;
}





