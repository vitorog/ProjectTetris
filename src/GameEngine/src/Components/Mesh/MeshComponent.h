/*
 * MeshComponent.h
 *
 *  Created on: 09/03/2012
 *      Author: Vitor
 */
#pragma once
#ifndef MESHCOMPONENT_H_
#define MESHCOMPONENT_H_

#include "Components/GameObjComponent.h"
#include "utils.h"

class MeshComponent : public GameObjComponent {
public:
	MeshComponent();
	virtual ~MeshComponent();
	void setMesh(const std::vector<glm::vec3>& vertices);
	std::vector<glm::vec3>& getVertices();
public:
	std::vector<glm::vec3> m_vertices;
};

#endif /* MESHCOMPONENT_H_ */
