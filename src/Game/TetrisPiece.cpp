/*
 * TetrisPiece.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */
#include "TetrisPiece.h"



#include "GameEngine/src/Components/Collision/CollisionComponent.h"
#include "GameEngine/src/Components/Material/MaterialComponent.h"
#include <iterator>
#include <iostream>
#define TETRIS_BLOCK_SIZE 1.0f

TetrisPiece::TetrisPiece(TetrisPieceType type, glm::vec3 position) {
	m_previous_mov = -1;
	m_type = type;
	m_frame.setCenter(glm::vec3());
	createBlocks();
	setPosition(position);
	m_rotated_angle = 0;
	m_current_rotation = 0;
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
		GameObject* new_block = new TetrisBlock(position[i]);
		m_children.push_back(new_block);
	}
}

void TetrisPiece::movePiece(TetrisPieceDirection dir) {
	switch(dir){
	case LEFT:
		move(-MOVE_DISTANCE,0.0f);
		m_previous_mov = LEFT;
		break;
	case RIGHT:
		move(MOVE_DISTANCE,0.0f);
		m_previous_mov = RIGHT;
		break;
	case UP:
		move(0.0f,MOVE_DISTANCE);
		m_previous_mov = UP;
		break;
	case DOWN:
		move(0.0f,-MOVE_DISTANCE);
		m_previous_mov = DOWN;
		break;
	default:
		break;
	}
}

void TetrisPiece::rotatePiece()
{
	if(m_type != TETRIS_SQUARE_PIECE){
		m_current_rotation++;
		if(m_current_rotation > 3){
			m_current_rotation = 0;
		}
		if(m_type <= 3){
			if(m_current_rotation > 1){
				m_current_rotation = 0;
			}
		}
		TetrisPieceRotation rot;
		switch(m_current_rotation)
		{
		case 0:
			rot = ROT_0;
			break;
		case 1:
			rot = ROT_90;
			break;
		case 2:
			rot = ROT_180;
			break;
		case 3:
			rot = ROT_270;
			break;
		}
		setRotation(rot);
	}
}



bool TetrisPiece::checkCollision(GameObject* object)
{
	std::list<GameObject*>* children = object->getChildren();
	std::list<GameObject*>::iterator other_it;
	TetrisBlock* block = nullptr;
	if( children->size() > 0){
		for(int i = 0; i < 4; i++){
			block = this->getTetrisBlock(i);
			for(other_it = children->begin(); other_it != children->end(); other_it++){
				if(block != nullptr){
					if(block->checkCollision((*other_it))){
						return true;
					}
				}
			}
		}
	}else{
		CollisionComponent* collision_cmp = dynamic_cast<CollisionComponent*>(object->getComponent(COLLISION_COMPONENT));
		if(collision_cmp != nullptr){
			for(int i = 0; i < 4; i++){
				block = this->getTetrisBlock(i);
				if(collision_cmp->checkCollision(block)){
						return true;
				}
			}
		}
	}
	return false;
}

void TetrisPiece::setMaterial(glm::vec3 test)
{
	MaterialComponent* material_cmp = dynamic_cast<MaterialComponent*>(getComponent(MATERIAL_COMPONENT));
	if(material_cmp != nullptr){
		material_cmp->setMaterial(test);
	}
	std::list<GameObject*>::iterator it;
	for(it = m_children.begin(); it != m_children.end(); it++){
		material_cmp = dynamic_cast<MaterialComponent*>((*it)->getComponent(MATERIAL_COMPONENT));
		if(material_cmp != nullptr){
				material_cmp->setMaterial(test);
		}
	}
}

void TetrisPiece::undoRotation()
{
	if(m_type != TETRIS_SQUARE_PIECE)
	{
		if(m_type <= 3){
			rotatePiece();
		}else{
			switch(m_current_rotation)
			{
			case 0:
				setRotation(ROT_270);
				break;
			case 1:
				setRotation(ROT_0);
				break;
			case 2:
				setRotation(ROT_90);
				break;
			case 3:
				setRotation(ROT_180);
				break;
			}
		}
	}
	m_current_rotation--;
}


TetrisBlock* TetrisPiece::getTetrisBlock(int pos)
{
	std::list<GameObject*>::iterator it;
	it = m_children.begin();
	std::advance(it, pos);
	TetrisBlock* block = nullptr;
	if(it != m_children.end()){
		block = dynamic_cast<TetrisBlock*>((*it));
		if(block != nullptr){
			return block;
		}
	}
	return nullptr;
}


void TetrisPiece::undoMovement()
{
	switch(m_previous_mov){
		case LEFT:
			move(MOVE_DISTANCE,0.0f);
			break;
		case RIGHT:
			move(-MOVE_DISTANCE,0.0f);
			break;
		case UP:
			move(0.0f,-MOVE_DISTANCE);
			break;
		case DOWN:
			move(0.0f,MOVE_DISTANCE);
			break;
		default:
			break;
	}
	m_previous_mov = -1;
}

void TetrisPiece::setRotation(TetrisPieceRotation rotation)
{
	m_frame.resetRotation();
	switch(rotation)
	{
	case ROT_0:
		rotate(0.0f,glm::vec3(0.0f,0.0f,-1.0f));
		break;
	case ROT_90:
		rotate(90.0f,glm::vec3(0.0f,0.0f,-1.0f));
		break;
	case ROT_180:
		rotate(180.0f,glm::vec3(0.0f,0.0f,-1.0f));
		break;
	case ROT_270:
		rotate(270.0f,glm::vec3(0.0f,0.0f,-1.0f));
		break;
	}
}






