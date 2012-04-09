/*
 * SceneManager.h
 *
 *  Created on: 08/04/2012
 *      Author: Vitor
 */

#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

class VideoManager;
class InputManager;
class GameScene;
class Timer;

#include <vector>



class SceneManager {
public:
	virtual ~SceneManager();
	static SceneManager* getInstance();
	void run();

	void addScene(GameScene *scene);
	void removeScene(unsigned int id);
	void changeFps(unsigned int fps);
	void manageFps();
private:
	SceneManager();
	std::vector<GameScene*> m_scenes;
	GameScene* m_current_scene;
	static SceneManager* m_scene_mng;
	VideoManager* m_video_mng;
	InputManager* m_input_mng;
	bool m_running;
	unsigned int m_fps;
	Timer* m_fps_timer;
};

#endif /* SCENEMANAGER_H_ */
