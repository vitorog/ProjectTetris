/*
 * TetrisGameInstance.h
 *
 *  Created on: 08/04/2012
 *      Author: Vitor
 */

#ifndef TETRISGAMEINSTANCE_H_
#define TETRISGAMEINSTANCE_H_

#include "GameEngine/src/GameInstance.h"

class TetrisGameInstance: public GameInstance {
public:
	TetrisGameInstance();
	virtual ~TetrisGameInstance();
	void start();
	void loadScenes();
};

#endif /* TETRISGAMEINSTANCE_H_ */
