/*
 * TetrisBlock.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#include "TetrisBlock.h"

TetrisBlock::TetrisBlock(glm::vec3 position, float size) {
	m_frame.setCenter(position);
	CollisionComponent* collision = new CollisionComponent(&m_frame);
	addComponent(collision);

	RendererComponent* renderer = new RendererComponent();
	addComponent(renderer);

	MeshComponent* mesh = new MeshComponent();
	addComponent(mesh);

	float hsize = size/2;
	glm::vec3 origin = glm::vec3();
	glm::vec3 v1 = origin;
	v1.x -= hsize;
	v1.y -= hsize;

	glm::vec3 v2 = origin;
	v2.x += hsize;
	v2.y -= hsize;

	glm::vec3 v3 = origin;
	v3.x += hsize;
	v3.y += hsize;

	glm::vec3 v4 = origin;
	v4.x -= hsize;
	v4.y += hsize;

	std::vector<glm::vec3> vertices = { v1, v2, v3, v4 };
	mesh->setMesh(vertices);

	glm::vec3 color;
	color.x = 128;
	color.y = 0;
	color.z = 128;
	MaterialComponent* material = new MaterialComponent(color);
	addComponent(material);
}

TetrisBlock::~TetrisBlock() {
}


bool TetrisBlock::checkCollision(GameObject* block){
	CollisionComponent* collision_cmpt = dynamic_cast<CollisionComponent*>(this->getComponent(COLLISION_COMPONENT));
	if(collision_cmpt != nullptr){
		if(collision_cmpt->checkCollision(block)){
			return true;
		}
	}
	return false;
}
