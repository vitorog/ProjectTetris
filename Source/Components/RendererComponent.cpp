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

void RendererComponent::render() {
	glBegin(GL_QUADS);
		glVertex3f(-1.0f,-1.0f,0.0f);
		glVertex3f(1.0f,-1.0f,0.0f);
		glVertex3f(1.0f,1.0f,0.0f);
		glVertex3f(-1.0f,1.0f,0.0f);
	glEnd();
}


