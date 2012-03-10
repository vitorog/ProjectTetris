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
	while(m_running){
		GameObject* tetris_piece = new TetrisPiece(i);
		TetrisPiece* tp = dynamic_cast<TetrisPiece*>(tetris_piece);
		tp->movePiece(DOWN);
		addGameObj(tetris_piece);
		input(event);
		logic();
		render();
		m_game_objs_list.clear();
		i++;
		if(i  > 6){
			i = 0;
		}
		SDL_Delay(500);
	}
}

void GameManager::logic() {
}

void GameManager::input(SDL_Event event) {
	//Move this to input manager later
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			m_running = false;
		}
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


void GameManager::createTetrisPiece() {
	GameObject* tetris_piece = new TetrisPiece(6);
	addGameObj(tetris_piece);
	//return dynamic_cast<TetrisPiece*>(tetris_piece);
}








