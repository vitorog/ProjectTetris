/*
 * GameManager.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#include "GameManager.h"


#define FRAMES_PER_SECOND 60
#define DROP_TIME 500

GameManager* GameManager::m_game_mng = nullptr;

SDL_Event event;

GameManager::GameManager() {
	m_running = true;
	m_video_mng = VideoManager::getInstance();
	m_video_mng->setupVideo();

	m_input_mng = InputManager::getInstance();

	m_fps_timer = new Timer();
	m_drop_timer = new Timer();

}

GameManager::~GameManager() {
	std::list<GameObject*>::iterator it;
	GameObject* curr_obj = nullptr;
	for(it = m_game_objs_list.begin(); it != m_game_objs_list.end(); it++){
		curr_obj = (*it);
		it = m_game_objs_list.erase(it);
		delete curr_obj;
	}
	delete m_fps_timer;
	delete m_drop_timer;
}

void GameManager::run() {
	GameObject* tetris_piece2 = new TetrisPiece(0, glm::vec3(5.0f,0.0f,0.0f));
	addGameObj(tetris_piece2);


	GameObject* tetris_piece = new TetrisPiece(0);
	TetrisPiece* tp = dynamic_cast<TetrisPiece*>(tetris_piece);
	m_curr_piece = tp;
	addGameObj(tetris_piece);
	m_drop_timer->start();

	while(m_running){
		m_fps_timer->start();
		input(event);
		logic();
		render();
		manageDropPiece();
		manageFps();
	}
}

void GameManager::logic() {
	if(checkCollision()){
		m_curr_piece->setMaterial(glm::vec3(1.0f,0.0f,0.0f));
		std::cout << "COLLILDED" << std::endl;
	}else{
		m_curr_piece->setMaterial(glm::vec3(0.0f,0.0f,1.0f));
		std::cout << "NOT COLLILDED" << std::endl;
	}
}

void GameManager::input(SDL_Event event) {

	if(m_input_mng->checkQuitApp()){
		m_running = false;
		return;
	}
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
	m_game_objs_list.push_front(obj);
}

void GameManager::manageFps() {
	if(m_fps_timer->getElapsed() < (1000 / FRAMES_PER_SECOND))
	{
			SDL_Delay((1000 / FRAMES_PER_SECOND) - m_fps_timer->getElapsed());
	}
}

void GameManager::manageDropPiece() {
	if(m_drop_timer->getElapsed() > DROP_TIME){
		//m_curr_piece->moveDir(DOWN);
		m_drop_timer->start();
	}
}

void GameManager::removeGameObj(int id) {
	std::list<GameObject*>::iterator it;
	for(it = m_game_objs_list.begin(); it != m_game_objs_list.end(); it++){
		if((*it)->getId() == id){
			m_game_objs_list.erase(it);
			return;
		}
	}
}

bool GameManager::checkCollision(){
	std::list<GameObject*>::iterator it;
	it = m_game_objs_list.begin();
	std::advance(it,1);
	for(; it != m_game_objs_list.end(); it++){
		if(m_curr_piece->checkCollision((*it))){
			return true;
		}
	}
	return false;
}
