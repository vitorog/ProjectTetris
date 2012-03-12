/*
 * MaterialComponent.cpp
 *
 *  Created on: 09/03/2012
 *      Author: Vitor
 */

#include "MaterialComponent.h"

MaterialComponent::MaterialComponent(glm::vec3 color) {
	m_color = color;
}

MaterialComponent::~MaterialComponent() {
}

glm::vec3 MaterialComponent::getColor() {
	return m_color;
}

bool MaterialComponent::hasTexture() {
	return m_textured;
}

void MaterialComponent::setMaterial(glm::vec3 color) {
	m_color = color;
}



