/*
 * TetrisBlock.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#include "TetrisBlock.h"

TetrisBlock::TetrisBlock(Point3 position) {
	RendererComponent* renderer = new RendererComponent();
	addComponent(renderer);
	MeshComponent* mesh = new MeshComponent();
	addComponent(mesh);

	Point3 v1 = position;
	v1.x -= 0.5f;
	v1.y -= 0.5f;

	Point3 v2 = position;
	v2.x += 0.5f;
	v2.y -= 0.5f;

	Point3 v3 = position;
	v3.x += 0.5f;
	v3.y += 0.5f;

	Point3 v4 = position;
	v4.x -= 0.5f;
	v4.y += 0.5f;

	std::vector<Point3> vertices = { v1, v2, v3, v4 };
	mesh->setMesh(vertices);
	m_frame.setCenter(position);
}

TetrisBlock::~TetrisBlock() {
}

