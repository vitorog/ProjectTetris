/*
 * GameScene.h
 *
 *  Created on: 08/04/2012
 *      Author: Vitor
 */
#pragma once
#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include <list>

class GameObject;
class InputManager;

class GameScene {
public:
	GameScene();
	virtual ~GameScene();
	virtual void setup() = 0;
	virtual void run() = 0;
	virtual void logic() = 0;
	virtual void input() = 0;
	virtual void render() = 0;
	void addGameObj(GameObject* obj);
	void removeGameObj(GameObject* obj);
	virtual bool checkRunning();
protected:
	std::list<GameObject*> m_game_objs_list;
	bool m_running;
	static unsigned int m_id;
	InputManager *m_input_mng;
};

#endif /* GAMESCENE_H_ */
