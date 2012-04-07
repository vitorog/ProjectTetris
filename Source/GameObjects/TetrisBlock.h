/*
 * TetrisBlock.h
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#ifndef TETRISBLOCK_H_
#define TETRISBLOCK_H_

#include "TetrisPiece.h"

class TetrisBlock : public GameObject {
public:
	TetrisBlock(glm::vec3 position, float size = 1.0f);
	virtual ~TetrisBlock();
	bool checkCollision(GameObject* block);
};

#endif /* TETRISBLOCK_H_ */
