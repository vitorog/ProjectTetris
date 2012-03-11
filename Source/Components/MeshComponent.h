/*
 * MeshComponent.h
 *
 *  Created on: 09/03/2012
 *      Author: Vitor
 */

#ifndef MESHCOMPONENT_H_
#define MESHCOMPONENT_H_

#include <vector>
#include "../ObjectFrame.h"
#include "GameObjComponent.h"

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
