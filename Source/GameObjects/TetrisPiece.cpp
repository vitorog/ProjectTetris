/*
 * TetrisPiece.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#include "TetrisPiece.h"

#include "TetrisBlock.h"
#include "../Components/CollisionComponent.h"

#include <iterator>

#define TETRIS_BLOCK_SIZE 1.0f

TetrisPiece::TetrisPiece(int type, glm::vec3 position) {
	m_type = type;
	m_frame.setCenter(position);
	std::cout << "Center: " << std::endl;
	std::cout << position.x << " " << position.y << " " << std::endl;
	createBlocks();
	std::cout << std::endl;
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
	CollisionComponent* collision_cmp = nullptr;
	std::list<GameObject*>::iterator it;
	TetrisBlock* curr_block = nullptr;
	for(it = m_children.begin(); it != m_children.end(); it++)
	{
		curr_block = dynamic_cast<TetrisBlock*>((*it));
		if(curr_block != nullptr){
			curr_block->getFrame().applyTransformation(this->getFrame().getTransformationMatrix());
			collision_cmp = dynamic_cast<CollisionComponent*>(curr_block->getComponent(COLLISION_COMPONENT));
			if(collision_cmp != nullptr){
				collision_cmp->updateBoundingBox();
			}

		}
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
	}
	return false;
}

void TetrisPiece::setMaterial(glm::vec3 test){
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


void TetrisPiece::printCenter(){
	std::cout << m_frame.getCenter().x << " " << m_frame.getCenter().y << " " << std::endl;
}
