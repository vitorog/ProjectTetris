/*
 * SceneManager.cpp
 *
 *  Created on: 08/04/2012
 *      Author: Vitor
 */

#include "SceneManager.h"

#include "Core/VideoManager.h"
#include "Core/InputManager.h"

#include "Scenes/GameScene.h"

#include "Core/Timer.h"

SDL_Event event;

SceneManager* SceneManager::m_scene_mng = nullptr;

SceneManager::SceneManager() {
	m_video_mng = VideoManager::getInstance();
	m_input_mng = InputManager::getInstance();
	m_fps_timer = new Timer();
	m_fps = 20;
}

SceneManager::~SceneManager() {
	delete m_fps_timer;
}

SceneManager* SceneManager::getInstance() {
	if(m_scene_mng == nullptr){
		m_scene_mng = new SceneManager();
	}
	return m_scene_mng;
}


void SceneManager::run()
{
	m_running = true;
	if(m_scenes.size() > 0){
		while(m_running){
			m_fps_timer->start();

			m_current_scene->input();
			m_current_scene->logic();

			m_video_mng->clearScreen();
			m_current_scene->render();
			m_video_mng->updateScreen();
			manageFps();

			if(m_input_mng->checkQuitApp() || (m_current_scene->checkRunning() == false)){
				m_running = false;
			}
		}
	}
}

void SceneManager::addScene(GameScene* scene)
{
	if(m_scenes.size() == 0){
		m_scenes.push_back(scene);
		m_current_scene = scene;
	}else{
		m_scenes.push_back(scene);
	}
	scene->setup();
}

void SceneManager::removeScene(unsigned int id)
{
}



void SceneManager::manageFps()
{
	if(m_fps_timer->getElapsed() < (1000 / m_fps))
	{
			SDL_Delay((1000 / m_fps) - m_fps_timer->getElapsed());
	}
}

void SceneManager::changeFps(unsigned int fps)
{
	m_fps = fps;
}





