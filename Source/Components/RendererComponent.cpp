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
	glBegin(GL_QUADS);
	//if(material != nullptr){
	std::vector<Point3> vertices = mesh->getVertices();
	std::vector<Point3>::iterator verts_it;
	for(verts_it = vertices.begin(); verts_it != vertices.end(); verts_it++){
		glVertex3f((*verts_it).x,(*verts_it).y,(*verts_it).z);
	}
	//}else{

	//}
	glEnd();
//	float hsize = 1.0f/2;
//	Point3 center;
//	glBegin(GL_QUADS);
//		glVertex3f(center.x - hsize, center.y - hsize, center.z );
//		glVertex3f(center.x + hsize, center.y - hsize, center.z );
//		glVertex3f(center.x + hsize, center.y + hsize, center.z );
//		glVertex3f(center.x - hsize, center.y + hsize, center.z );
//	glEnd();
}



