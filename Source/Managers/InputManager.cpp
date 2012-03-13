/*
 * InputManager.cpp
 *
 *  Created on: 10/03/2012
 *      Author: Vitor
 */

#include "InputManager.h"


InputManager* InputManager::m_input_mng_ptr = nullptr;

InputManager::InputManager() {
	m_quit = false;
	m_disable_key_hold = true;
}

InputManager::~InputManager() {
	// TODO Auto-generated destructor stub
}

void InputManager::handleInput(SDL_Event event) {
	if(m_disable_key_hold){
		m_keys_set.clear();
	}
	if(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			m_quit = true;
		}
		if(event.type == SDL_KEYDOWN){
			handleKeyPresses(event);
		}
		if(event.type == SDL_KEYUP){
			handleKeyReleases(event);
		}
	}
}

bool InputManager::checkKey(std::string key) {
	if(m_keys_set.find(key) != m_keys_set.end()){
		return true;
	}
	return false;
}

InputManager* InputManager::getInstance() {
	if(m_input_mng_ptr == nullptr){
		m_input_mng_ptr = new InputManager();
	}
	return m_input_mng_ptr;
}

void InputManager::handleKeyPresses(SDL_Event event) {
	switch(event.key.keysym.sym){
	case SDLK_UP:
		m_keys_set.insert("UP");
		break;
	case SDLK_DOWN:
		m_keys_set.insert("DOWN");
		break;
	case SDLK_RIGHT:
		m_keys_set.insert("RIGHT");
		break;
	case SDLK_LEFT:
		m_keys_set.insert("LEFT");
		break;
	case SDLK_SPACE:
		m_keys_set.insert("SPACE");
		break;
	case SDLK_LCTRL:
		m_keys_set.insert("LCTRL");
		break;
	default:
		break;
	}
}

void InputManager::handleKeyReleases(SDL_Event event) {
	switch(event.key.keysym.sym){
	case SDLK_UP:
		m_keys_set.erase("UP");
		break;
	case SDLK_DOWN:
		m_keys_set.erase("DOWN");
		break;
	case SDLK_RIGHT:
		m_keys_set.erase("RIGHT");
		break;
	case SDLK_LEFT:
		m_keys_set.erase("LEFT");
		break;
	default:
		break;
	}
}

bool InputManager::checkQuitApp()
{
	return m_quit;
}



