/*
 * GameManager.h
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */
#pragma once
#ifndef TETRISGAMESCENE_H
#define TETRISGAMESCENE_H

#include "GameEngine/src/Scenes/GameScene.h"
#include "TetrisPiece.h"

#include <ctime>

class Timer;

class TetrisGameScene : public GameScene {
public:
	TetrisGameScene();
	virtual ~TetrisGameScene();
	void run();
	void setup();
	void logic();
	void input();
	void render();
private:
	void manageDropPiece();
	void generatePiece();
	void createBorders(int pos);
	void checkTetrisLines();
	void clearLine(unsigned int line);
	void dropLine(unsigned int line);
	TetrisPiece* m_curr_piece;
	TetrisPiece* m_preview_piece;
	bool checkCollision();
	TetrisPiece* createTetrisPiece(TetrisPieceType type);
	int m_next_piece_type;
	Timer* m_drop_timer;
	std::vector<std::vector<TetrisBlock*>> m_tetris_blocks;
	unsigned int m_score;
	int m_dropdown_time;
};

#endif /* TETRISGAMESCENE_H */
