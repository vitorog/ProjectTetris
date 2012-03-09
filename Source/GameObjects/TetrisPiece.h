/*
 * TetrisPiece.h
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#ifndef TETRISPIECE_H_
#define TETRISPIECE_H_

#include <vector>

#include "GameObject.h"
#include "TetrisBlock.h"


class TetrisPiece : public GameObject {
public:
	TetrisPiece(int type);
	virtual ~TetrisPiece();
	void createBlocks();
	std::vector<TetrisBlock*> m_blocks;
	int m_type;
};

#endif /* TETRISPIECE_H_ */
