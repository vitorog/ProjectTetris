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
	void setMesh(const std::vector<Point3>& vertices);
	std::vector<Point3>& getVertices();
public:
	std::vector<Point3> m_vertices;
};

#endif /* MESHCOMPONENT_H_ */
