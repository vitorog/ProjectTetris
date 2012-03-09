/*
 * ScreenManager.cpp
 *
 *  Created on: 06/03/2012
 *      Author: Vitor
 */

#include "VideoManager.h"

VideoManager* VideoManager::m_screen_mng_ptr = nullptr;

VideoManager::VideoManager()
{
}

void VideoManager::setupVideo(unsigned int width, unsigned int height,
		unsigned int depth, unsigned int flags)
{
	initSDL();
	createScreen(width,height,32,SDL_OPENGL);
	initGL();
}

VideoManager::~VideoManager()
{
	// TODO Auto-generated destructor stub
}

VideoManager* VideoManager::getInstance()
{
	if(m_screen_mng_ptr == nullptr){
		m_screen_mng_ptr = new VideoManager();
	}
	return m_screen_mng_ptr;
}

SDL_Surface* VideoManager::getScreen()
{
	return m_screen_ptr;
}

int VideoManager::initSDL() {
	int ret =  SDL_Init(SDL_INIT_VIDEO);
	if(ret < 0)
	{
		std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
	}
	return ret;
}

int VideoManager::initGL() {
	glClearColor(0.2f,0.2f,0.2f,1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double ratio = (double)m_screen_width/(double)m_screen_height;
	gluPerspective(45.0f, ratio ,0.01f,100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f,0.0f,25.0f,0.0f,0.0f,-1.0f,0.0f,1.0f,0.0f);
	return 0;
}

void VideoManager::updateScreen() {
	SDL_GL_SwapBuffers();
}

void VideoManager::clearScreen() {
	glClear(GL_COLOR_BUFFER_BIT);
}

int VideoManager::createScreen(unsigned int width, unsigned int height,
		unsigned int depth, unsigned int flags) {
	m_screen_width = width;
	m_screen_height = height;
	m_screen_ptr = SDL_SetVideoMode(width, height, depth, flags);
	if(m_screen_ptr == nullptr){
		return -1;
	}
	return 0;
}


