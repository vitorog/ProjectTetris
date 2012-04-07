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
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3>::iterator verts_it;

//	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	glBegin(GL_QUADS);
//
//
//	for(verts_it = vertices.begin(); verts_it != vertices.end(); verts_it++){
//		glVertex3f((*verts_it).x,(*verts_it).y,(*verts_it).z);
//	}
//	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	vertices = mesh->getVertices();
	glBegin(GL_QUADS);
	if(material != nullptr){
		glm::vec3 color = material->getColor();
		glColor3f(color.r,color.g,color.b);
	}else{
		glColor3f(1.0f,1.0f,1.0f);
	}
	for(verts_it = vertices.begin(); verts_it != vertices.end(); verts_it++){
		glVertex3f((*verts_it).x,(*verts_it).y,(*verts_it).z);
	}
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glBegin(GL_QUADS);
	glColor3f(0.0f,0.0f,0.0f);
	for(verts_it = vertices.begin(); verts_it != vertices.end(); verts_it++){
		glVertex3f((*verts_it).x,(*verts_it).y,(*verts_it).z);
	}
	glEnd();
}



