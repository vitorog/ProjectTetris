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

#define MOVE_DISTANCE 1.0f

typedef enum TetrisPieceType_t {
	TETRIS_SQUARE_PIECE = 0,
	TETRIS_LINE_PIECE,
	TETRIS_S_PIECE,
	TETRIS_Z_PIECE,
	TETRIS_L_PIECE,
	TETRIS_J_PIECE,
	TETRIS_T_PIECE
}TetrisPieceType;

typedef enum TetrisPieceDirection_t {
	LEFT = 0,
	RIGHT,
	UP,
	DOWN
}TetrisPieceDirection;


class TetrisBlock;

class TetrisPiece : public GameObject {
public:
	TetrisPiece(int type, glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f));
	virtual ~TetrisPiece();
	void createBlocks();
	void moveDir(TetrisPieceDirection dir);
	bool checkCollision(GameObject* object);
	void setMaterial(glm::vec3 test);
	TetrisBlock* getTetrisBlock(int pos);
	void printCenter();
private:
	void move(float x, float y);
	int m_type;

};

#endif /* TETRISPIECE_H_ */
