/*
 * MaterialComponent.h
 *
 *  Created on: 09/03/2012
 *      Author: Vitor
 */
#pragma once
#ifndef MATERIALCOMPONENT_H_
#define MATERIALCOMPONENT_H_

#include "Components/GameObjComponent.h"
#include "utils.h"

class MaterialComponent : public GameObjComponent{
public:
	MaterialComponent(glm::vec3 color);
	virtual ~MaterialComponent();
	glm::vec3 getColor();
	bool hasTexture();
	void setMaterial(glm::vec3 color);
private:
	glm::vec3 m_color;
	bool m_textured;
};

#endif /* MATERIALCOMPONENT_H_ */
