/*
 * ObjectFrame.h
 *
 *  Created on: 09/03/2012
 *      Author: Vitor
 */

#ifndef OBJECTFRAME_H_
#define OBJECTFRAME_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ObjectFrame {
public:
	ObjectFrame();
	~ObjectFrame() = default;
	void setCenter(glm::vec3 position);
	glm::vec3 getCenter();
	glm::mat4x4& getTransformationMatrix();
	void setTransformationMatrix(glm::mat4x4& transformation_matrix);
	void translate(glm::vec3 direction);
	void rotate(float angle, glm::vec3 axis);
private:
	void updateCenter();
	glm::vec3 m_center;
	glm::mat4x4 m_transformation_matrix;
};

#endif /* OBJECTFRAME_H_ */
