/*
 * GameManager.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#include "GameManager.h"


GameManager* GameManager::m_game_mng = nullptr;

SDL_Event event;

GameManager::GameManager() {
	m_running = true;
	m_video_mng = VideoManager::getInstance();
	m_video_mng->setupVideo();

	m_input_mng = InputManager::getInstance();

}

GameManager::~GameManager() {
	std::list<GameObject*>::iterator it;
	GameObject* curr_obj = nullptr;
	for(it = m_game_objs_list.begin(); it != m_game_objs_list.end(); it++){
		curr_obj = (*it);
		it = m_game_objs_list.erase(it);
		delete curr_obj;
	}
}

void GameManager::run() {
	int i = 0;
	GameObject* tetris_piece = new TetrisPiece(i);
	TetrisPiece* tp = dynamic_cast<TetrisPiece*>(tetris_piece);
	m_curr_piece = tp;
	addGameObj(tetris_piece);
	while(m_running){
		input(event);
		logic();
		render();
	}
}

void GameManager::logic() {
}

void GameManager::input(SDL_Event event) {
	checkQuit(event);
	m_input_mng->handleInput(event);
	if(m_input_mng->checkKey("DOWN"))
	{
		m_curr_piece->moveDir(DOWN);
	}
	if(m_input_mng->checkKey("UP"))
		{
			m_curr_piece->moveDir(UP);
		}
	if(m_input_mng->checkKey("LEFT"))
		{
			m_curr_piece->moveDir(LEFT);
		}
	if(m_input_mng->checkKey("RIGHT"))
		{
			m_curr_piece->moveDir(RIGHT);
		}
	if(m_input_mng->checkKey("SPACE"))
	{
		m_running = false;
	}

}

GameManager* GameManager::getInstance() {
	if(m_game_mng == nullptr){
		m_game_mng = new GameManager();
	}
	return m_game_mng;
}

void GameManager::render() {
	m_video_mng->clearScreen();
	std::list<GameObject*>::iterator it;
	for(it = m_game_objs_list.begin(); it != m_game_objs_list.end(); it++){
		(*it)->render();
	}
	m_video_mng->updateScreen();
}

void GameManager::addGameObj(GameObject* obj) {
	m_game_objs_list.push_back(obj);
}

void GameManager::removeGameObj(GameObject* obj) {
}


void GameManager::checkQuit(SDL_Event event) {
//	//if(SDL_PeepEvents(&event,1,SDL_PEEKEVENT,)){
//		if(event.type == SDL_QUIT){
//				m_running = false;
//		}
//	}
}

void GameManager::createTetrisPiece() {
	GameObject* tetris_piece = new TetrisPiece(6);
	addGameObj(tetris_piece);
	//return dynamic_cast<TetrisPiece*>(tetris_piece);
}








