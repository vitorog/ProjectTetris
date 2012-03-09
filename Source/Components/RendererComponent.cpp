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

void RendererComponent::render(Point3 center, float size, Point3 color) {
	float hsize = size/2;
	glColor3f(color.x,color.y,color.z);
	glBegin(GL_QUADS);
		glVertex3f(center.x - hsize, center.y - hsize, center.z );
		glVertex3f(center.x + hsize, center.y - hsize, center.z );
		glVertex3f(center.x + hsize, center.y + hsize, center.z );
		glVertex3f(center.x - hsize, center.y + hsize, center.z );
	glEnd();
}


