/*
 * TimeManager.cpp
 *
 *  Created on: 10/03/2012
 *      Author: Vitor
 */

#include "Timer.h"

Timer::Timer() {
	m_paused = false;
}

Timer::~Timer() {
	// TODO Auto-generated destructor stub
}

void Timer::start() {
	m_time = SDL_GetTicks();
}

void Timer::pause() {
	m_paused = true;
}

unsigned int Timer::getElapsed() {
	return (SDL_GetTicks() - m_time);
}

void Timer::restart() {
}


