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
	TetrisPiece(TetrisPieceType type, glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f));
	virtual ~TetrisPiece();

	int getPreviousMoveType();
	void createBlocks();
	void movePiece(TetrisPieceDirection dir);
	void undoMovement();
	void undoRotation();
	void rotatePiece(TetrisPieceDirection dir);
	bool checkCollision(GameObject* object);
	void setMaterial(glm::vec3 test);
	TetrisBlock* getTetrisBlock(int pos);
private:
	int m_type;
	int m_previous_mov;
	int m_previous_move_type;
	float m_rotated_angle;
};

#endif /* TETRISPIECE_H_ */
