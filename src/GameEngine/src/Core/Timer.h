/*
 * TimeManager.h
 *
 *  Created on: 10/03/2012
 *      Author: Vitor
 */
#pragma once
#ifndef TIMEMANAGER_H_
#define TIMEMANAGER_H_

#include <SDL/SDL_timer.h>

class Timer {
public:
	Timer();
	virtual ~Timer();
	void start();
	void pause();
	unsigned int getElapsed();
	void restart();

private:
	unsigned int m_time;
	bool m_paused;
};

#endif /* TIMEMANAGER_H_ */
