/*
 * RendererComponent.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#include "RendererComponent.h"

RendererComponent::RendererComponent() {
	// TODO Auto-generated constructor stub

}

RendererComponent::~RendererComponent() {
	// TODO Auto-generated destructor stub
}



void RendererComponent::render(const ObjectFrame& frame, MeshComponent* mesh, MaterialComponent* material) {
	std::vector<Point3> vertices;
	std::vector<Point3>::iterator verts_it;

//	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	glBegin(GL_QUADS);
//
//
//	for(verts_it = vertices.begin(); verts_it != vertices.end(); verts_it++){
//		glVertex3f((*verts_it).x,(*verts_it).y,(*verts_it).z);
//	}
//	glEnd();


	glBegin(GL_QUADS);
	if(material != nullptr){
		Point3 color = material->getColor();
		glColor3f(color.x,color.y,color.z);
	}
	vertices = mesh->getVertices();
	for(verts_it = vertices.begin(); verts_it != vertices.end(); verts_it++){
		glVertex3f((*verts_it).x,(*verts_it).y,(*verts_it).z);
	}
	glEnd();
}



