/*
 * TetrisPiece.h
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */
#pragma once
#ifndef TETRISPIECE_H_
#define TETRISPIECE_H_

#include "TetrisBlock.h"
#include "GameEngine/src/GameObjects/GameObject.h"

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

typedef enum TetrisPieceRotation_t {
	ROT_0 = 0,
	ROT_90,
	ROT_180,
	ROT_270
}TetrisPieceRotation;


class TetrisPiece : public GameObject {
public:
	TetrisPiece(TetrisPieceType type, glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f));
	virtual ~TetrisPiece();

	void createBlocks();
	void movePiece(TetrisPieceDirection dir);
	void undoMovement();
	void undoRotation();
	void rotatePiece();
	bool checkCollision(GameObject* object);
	void setMaterial(glm::vec3 test);
	TetrisBlock* getTetrisBlock(int pos);
private:
	void setRotation(TetrisPieceRotation rotation);
	int m_type;
	int m_previous_mov;
	unsigned int m_current_rotation;
	float m_rotated_angle;
};

#endif /* TETRISPIECE_H_ */
