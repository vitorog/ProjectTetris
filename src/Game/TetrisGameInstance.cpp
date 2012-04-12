/*
 * TetrisGameInstance.cpp
 *
 *  Created on: 08/04/2012
 *      Author: Vitor
 */

#include "TetrisGameInstance.h"

#include "TetrisGameScene.h"
#include "TestScene.h"

TetrisGameInstance::TetrisGameInstance() {
	m_scene_manager = SceneManager::getInstance();
	m_video_manager = VideoManager::getInstance();
}

TetrisGameInstance::~TetrisGameInstance() {
	// TODO Auto-generated destructor stub
}

void TetrisGameInstance::start() {
	m_video_manager->setupVideo();
	if(m_scene_manager != nullptr){
		loadScenes();
		m_scene_manager->run();
	}
}

void TetrisGameInstance::loadScenes() {
//	TetrisGameScene *tetris_game_scene = new TetrisGameScene();
//	m_scene_manager->addScene(tetris_game_scene);
	TestScene *test_scene = new TestScene();
	m_scene_manager->addScene(test_scene);
}



