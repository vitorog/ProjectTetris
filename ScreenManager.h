/*
 * ScreenManager.h
 *
 *  Created on: 06/03/2012
 *      Author: Vitor
 */

#ifndef SCREENMANAGER_H_
#define SCREENMANAGER_H_

#include <SDL/SDL.h>
#include <SDL/SDL_main.h>

class ScreenManager {
public:
	ScreenManager();
	ScreenManager(unsigned int width, unsigned int height, unsigned int depth = 32, unsigned int flags = 0);
	virtual ~ScreenManager();
	ScreenManager* getInstance();
	SDL_Surface* getScreen();
private:
	int createScreen(unsigned int width, unsigned int height, unsigned int depth = 32, unsigned int flags = 0 );
	static ScreenManager* m_screen_mng_ptr;
	SDL_Surface *m_screen_ptr;

	unsigned int m_width;
	unsigned int m_height;
};


#endif /* SCREENMANAGER_H_ */
