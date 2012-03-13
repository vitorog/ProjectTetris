/*
 * ObjectFrame.h
 *
 *  Created on: 09/03/2012
 *      Author: Vitor
 */

#ifndef OBJECTFRAME_H_
#define OBJECTFRAME_H_

#include "utils.h"

#define PI 3.14159265

class ObjectFrame {
public:
	ObjectFrame();
	~ObjectFrame() = default;
	void setCenter(glm::vec3 position);
	glm::vec3 getCenter();
	glm::mat4x4& getTransformationMatrix();
	glm::mat4x4& getRotationMatrix();
	glm::mat4x4& getTranslationMatrix();
	void applyTransformation(glm::mat4x4& transformation_matrix);
	void setTransformationMatrix(glm::mat4x4& transformation_matrix);
	void translate(glm::vec3 direction);
	void rotate(float angle, glm::vec3 axis);
	void resetRotation();
private:
	void updateTransformationMatrix();
	void updateCenter();
	void printTransformationMatrix();
	glm::vec3 m_center;
	glm::vec3 m_translate_vec;
	glm::vec3 m_rotate_vec;
	float m_last_angle;
	glm::mat4x4 m_translation_matrix;
	glm::mat4x4 m_rotation_matrix;
	glm::mat4x4 m_transformation_matrix;
};

#endif /* OBJECTFRAME_H_ */
