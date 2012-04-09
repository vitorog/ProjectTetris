/*
 * TetrisBlock.h
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */
#pragma once
#ifndef TETRISBLOCK_H_
#define TETRISBLOCK_H_

#include "GameEngine/src/GameObjects/GameObject.h"

class TetrisBlock : public GameObject {
public:
	TetrisBlock(glm::vec3 position, float size = 1.0f);
	virtual ~TetrisBlock();
	bool checkCollision(GameObject* block);
};

#endif /* TETRISBLOCK_H_ */
