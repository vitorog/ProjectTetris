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

typedef enum TetrisPieceType_t {
	TETRIS_SQUARE_PIECE = 0,
	TETRIS_LINE_PIECE,
	TETRIS_S_PIECE,
	TETRIS_Z_PIECE,
	TETRIS_L_PIECE,
	TETRIS_J_PIECE,
	TETRIS_T_PIECE
}TetrisPieceType;

class TetrisPiece : public GameObject {
public:
	TetrisPiece(int type);
	virtual ~TetrisPiece();
	void createBlocks();
private:
	std::vector<TetrisBlock*> m_blocks;
	int m_type;
};

#endif /* TETRISPIECE_H_ */
