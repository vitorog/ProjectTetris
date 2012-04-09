/*
 * GameInstance.h
 *
 *  Created on: 08/04/2012
 *      Author: Vitor
 */
#pragma once
#ifndef GAMEINSTANCE_H_
#define GAMEINSTANCE_H_

#include "Scenes/SceneManager.h"
#include "Core/VideoManager.h"

class GameInstance {
public:
	GameInstance();
	virtual ~GameInstance();
	virtual void start() = 0;
	virtual void loadScenes() = 0;
protected:
	SceneManager *m_scene_manager;
	VideoManager *m_video_manager;
};

#endif /* GAMEINSTANCE_H_ */
