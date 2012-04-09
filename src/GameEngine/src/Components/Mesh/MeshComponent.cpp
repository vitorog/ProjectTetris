/*
 * MeshComponent.cpp
 *
 *  Created on: 09/03/2012
 *      Author: Vitor
 */

#include "MeshComponent.h"

MeshComponent::MeshComponent() {
	// TODO Auto-generated constructor stub

}

MeshComponent::~MeshComponent() {
	// TODO Auto-generated destructor stub
}

void MeshComponent::setMesh(const std::vector<glm::vec3>& vertices) {
	std::vector<glm::vec3>::const_iterator verts_it;
	for(verts_it = vertices.begin(); verts_it != vertices.end(); verts_it++){
		m_vertices.push_back((*verts_it));
	}
}

std::vector<glm::vec3>& MeshComponent::getVertices() {
	return m_vertices;
}


