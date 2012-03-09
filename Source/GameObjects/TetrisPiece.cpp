/*
 * TetrisPiece.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#include "TetrisPiece.h"

#define TETRIS_BLOCK_SIZE 1.0f

TetrisPiece::TetrisPiece(int type) {
	m_center.x = 0.0f;
	m_center.y = 0.0f;
	m_center.z = 0.0f;
	m_type = type;
	createBlocks();
}

TetrisPiece::~TetrisPiece() {
	// TODO Auto-generated destructor stub
}

void TetrisPiece::createBlocks() {
	Point3 position[4] = { m_center, m_center, m_center, m_center };
	Point3 color[4];
	color[0].x = 1.0f;

	color[1].y = 1.0f;

	color[2].z = 1.0f;

	color[3].x = 1.0f;
	color[3].y = 1.0f;
	switch(m_type)
	{
	case 0:
		position[1].x -= 1.0f;
		position[2].x -= 1.0f;
		position[2].y -= 1.0f;
		position[3].y -= 1.0f;
		break;
	case 1:
		position[1].x -= 1.0f;
		position[2].x -= 2.0f;
		position[3].x += 1.0f;
		break;
	case 2:
		position[1].x += 1.0f;
		position[2].y -= 1.0f;
		position[2].x -= 1.0f;
		position[3].y -= 1.0f;
		break;
	case 3:
		position[1].x -= 1.0f;
		position[2].y -= 1.0f;
		position[3].y -= 1.0f;
		position[3].x += 1.0f;
		break;
	case 4:
		position[1].x -= 1.0f;
		position[2].x -= 1.0f;
		position[2].y -= 1.0f;
		position[3].x += 1.0f;
		break;
	case 5:
		position[1].x -= 1.0f;
		position[2].x += 1.0f;
		position[3].y -= 1.0f;
		position[3].x += 1.0f;
		break;
	case 6:
		position[1].x -= 1.0f;
		position[2].x += 1.0f;
		position[3].y -= 1.0f;
		break;
	default:
		break;
	}
	for(int i = 0; i < 4; i++){
		TetrisBlock* new_block = new TetrisBlock(position[i], color[i]);
		RendererComponent* block_renderer = new RendererComponent();
		new_block->addComponent(block_renderer);
		m_blocks.push_back(new_block);
		m_children.push_back(new_block);
	}
}


