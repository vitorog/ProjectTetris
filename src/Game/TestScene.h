/*
 * TestScene.h
 *
 *  Created on: 11/04/2012
 *      Author: Vitor
 */

#ifndef TESTSCENE_H_
#define TESTSCENE_H_

#include "GameEngine/src/Scenes/GameScene.h"

class TestScene : public GameScene {
public:
	TestScene();
	virtual ~TestScene();
	void render();
	void logic() {};
	void input();
	void run() {};
	void setup();
};

#endif /* TESTSCENE_H_ */
