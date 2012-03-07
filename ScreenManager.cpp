/*
 * ScreenManager.cpp
 *
 *  Created on: 06/03/2012
 *      Author: Vitor
 */

#include "ScreenManager.h"

ScreenManager* ScreenManager::m_screen_mng_ptr = nullptr;

ScreenManager::ScreenManager()
{
	// TODO Auto-generated constructor stub

}

ScreenManager::ScreenManager(unsigned int width, unsigned int height,
		unsigned int depth, unsigned int flags)
{
}

ScreenManager::~ScreenManager()
{
	// TODO Auto-generated destructor stub
}

ScreenManager* ScreenManager::getInstance()
{
	if(m_screen_mng_ptr == nullptr){
		m_screen_mng_ptr = new ScreenManager();
	}
	return m_screen_mng_ptr;
}

SDL_Surface* ScreenManager::getScreen()
{
	return m_screen_ptr;
}

int ScreenManager::createScreen(unsigned int width, unsigned int height,
		unsigned int depth, unsigned int flags) {
	m_screen_ptr = SDL_SetVideoMode(width, height, depth, flags);
	if(m_screen_ptr == nullptr){
		return -1;
	}
	return 0;
}


