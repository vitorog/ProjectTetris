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
	glm::vec3 center =  m_frame.getCenter();
	glm::vec3 position[4] = { center, center, center, center };
	glm::vec3 color[4];
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
		m_children.push_back(new_block);
	}
}

void TetrisPiece::moveDir(TetrisPieceDirection dir) {
	switch(dir){
	case LEFT:
		move(-MOVE_DISTANCE,0.0f);
		break;
	case RIGHT:
		move(MOVE_DISTANCE,0.0f);
		break;
	case UP:
		move(0.0f,MOVE_DISTANCE);
		break;
	case DOWN:
		move(0.0f,-MOVE_DISTANCE);
		break;
	default:
		break;
	}
}

void TetrisPiece::move(float x, float y) {
	m_frame.translate(glm::vec3(x,y,0));
	std::list<GameObject*>::iterator it;
	TetrisBlock* curr_block = nullptr;
	for(it = m_children.begin(); it != m_children.end(); it++)
	{
		curr_block = dynamic_cast<TetrisBlock*>((*it));
		if(curr_block != nullptr){
			curr_block->getFrame().translate(glm::vec3(x,y,0));
		}
	}
}



