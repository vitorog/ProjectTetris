/*
 * MaterialComponent.h
 *
 *  Created on: 09/03/2012
 *      Author: Vitor
 */

#ifndef MATERIALCOMPONENT_H_
#define MATERIALCOMPONENT_H_

#include "GameObjComponent.h"
#include "../ObjectFrame.h"

class MaterialComponent : public GameObjComponent{
public:
	MaterialComponent(glm::vec3 color);
	virtual ~MaterialComponent();
	glm::vec3 getColor();
	bool hasTexture();
private:
	glm::vec3 m_color;
	bool m_textured;
};

#endif /* MATERIALCOMPONENT_H_ */
