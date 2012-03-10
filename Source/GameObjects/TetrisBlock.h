/*
 * TetrisBlock.h
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#ifndef TETRISBLOCK_H_
#define TETRISBLOCK_H_

#include "GameObject.h"


class TetrisBlock : public GameObject {
public:
	TetrisBlock(Point3 position, float size = 1.0f);
	virtual ~TetrisBlock();

};

#endif /* TETRISBLOCK_H_ */
