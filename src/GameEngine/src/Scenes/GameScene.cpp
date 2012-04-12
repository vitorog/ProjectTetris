/*
 * GameScene.cpp
 *
 *  Created on: 08/04/2012
 *      Author: Vitor
 */

#include "GameScene.h"

#include "GameObjects/GameObject.h"
#include "Core/InputManager.h"


unsigned int GameScene::m_id = 0;

GameScene::GameScene() {
	m_input_mng = InputManager::getInstance();
}

GameScene::~GameScene() {

}

void GameScene::addGameObj(GameObject* obj) {
		m_game_objs_list.push_back(obj);
}

void GameScene::removeGameObj(GameObject *obj) {
	std::list<GameObject*>::iterator it;
	for(it = m_game_objs_list.begin(); it != m_game_objs_list.end(); it++){
		if(obj == (*it)){
			m_game_objs_list.erase(it);
			return;
		}
	}
}

void GameScene::setup() {
	m_running = true;
}

void GameScene::run() {
	input();
}

void GameScene::input() {
	m_input_mng->handleInput(input_event);
}

bool GameScene::checkRunning()
{
	return m_running;
}


