/*
 * TetrisPiece.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#include "TetrisPiece.h"

#define TETRIS_BLOCK_SIZE 1.0f

TetrisPiece::TetrisPiece(int type) {
	m_type = type;
	createBlocks();
}

TetrisPiece::~TetrisPiece() {
}

void TetrisPiece::createBlocks() {
	Point3 center =  m_frame.getCenter();
	Point3 position[4] = { center, center, center, center };
	Point3 color[4];
	color[0].x = 1.0f;

	color[1].y = 1.0f;

	color[2].z = 1.0f;

	color[3].x = 1.0f;
	color[3].y = 1.0f;
	switch(m_type)
	{
	case TETRIS_SQUARE_PIECE:
		position[1].x -= 1.0f;
		position[2].x -= 1.0f;
		position[2].y -= 1.0f;
		position[3].y -= 1.0f;
		break;
	case TETRIS_LINE_PIECE:
		position[1].x -= 1.0f;
		position[2].x -= 2.0f;
		position[3].x += 1.0f;
		break;
	case TETRIS_S_PIECE:
		position[1].x += 1.0f;
		position[2].y -= 1.0f;
		position[2].x -= 1.0f;
		position[3].y -= 1.0f;
		break;
	case TETRIS_Z_PIECE:
		position[1].x -= 1.0f;
		position[2].y -= 1.0f;
		position[3].y -= 1.0f;
		position[3].x += 1.0f;
		break;
	case TETRIS_L_PIECE:
		position[1].x -= 1.0f;
		position[2].x -= 1.0f;
		position[2].y -= 1.0f;
		position[3].x += 1.0f;
		break;
	case TETRIS_J_PIECE:
		position[1].x -= 1.0f;
		position[2].x += 1.0f;
		position[3].y -= 1.0f;
		position[3].x += 1.0f;
		break;
	case TETRIS_T_PIECE:
		position[1].x -= 1.0f;
		position[2].x += 1.0f;
		position[3].y -= 1.0f;
		break;
	default:
		break;
	}
	for(unsigned int i = 0; i < 4; i++){
		TetrisBlock* new_block = new TetrisBlock(position[i]);
		m_blocks.push_back(new_block);
		m_children.push_back(new_block);
	}
}


