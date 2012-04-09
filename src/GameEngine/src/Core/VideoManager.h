/*
 * ScreenManager.h
 *
 *  Created on: 06/03/2012
 *      Author: Vitor
 */

#pragma once
#ifndef SCREENMANAGER_H_
#define SCREENMANAGER_H_

#include <SDL/SDL_opengl.h>
#include <SDL/SDL_video.h>
#include <iostream>

class VideoManager {
public:
	void setupVideo(unsigned int width = 800, unsigned int height = 600, unsigned int depth = 32, unsigned int flags = SDL_OPENGL);
	virtual ~VideoManager();
	static VideoManager* getInstance();
	SDL_Surface* getScreen();
	void updateScreen();
	void clearScreen();
private:
	VideoManager();
	int initSDL();
	int initGL();
	int createScreen(unsigned int width, unsigned int height, unsigned int depth = 32, unsigned int flags = SDL_OPENGL );
	static VideoManager* m_screen_mng_ptr;
	SDL_Surface *m_screen_ptr;

	unsigned int m_screen_width;
	unsigned int m_screen_height;
};


#endif /* SCREENMANAGER_H_ */
