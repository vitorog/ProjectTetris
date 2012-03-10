/*
 * TetrisBlock.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#include "TetrisBlock.h"

TetrisBlock::TetrisBlock(Point3 position, float size) {
	RendererComponent* renderer = new RendererComponent();
	addComponent(renderer);
	MeshComponent* mesh = new MeshComponent();
	addComponent(mesh);
	Point3 color;
	color.x = 128;
	color.y = 0;
	color.z = 128;
	MaterialComponent* material = new MaterialComponent(color);
	addComponent(material);

	float hsize = size/2;

	Point3 v1 = position;
	v1.x -= hsize;
	v1.y -= hsize;

	Point3 v2 = position;
	v2.x += hsize;
	v2.y -= hsize;

	Point3 v3 = position;
	v3.x += hsize;
	v3.y += hsize;

	Point3 v4 = position;
	v4.x -= hsize;
	v4.y += hsize;

	std::vector<Point3> vertices = { v1, v2, v3, v4 };
	mesh->setMesh(vertices);
	m_frame.setCenter(position);
}

TetrisBlock::~TetrisBlock() {
}

