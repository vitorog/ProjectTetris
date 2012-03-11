/*
 * GameManager.h
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "VideoManager.h"
#include "InputManager.h"

#include "../GameObjects/GameObject.h"
#include "../GameObjects/TetrisBlock.h"
#include "../GameObjects/TetrisPiece.h"

#include "../Timer.h"


#include <list>

class GameManager {
public:
	virtual ~GameManager();
	void run();
	static GameManager* getInstance();
private:
	GameManager();
	void logic();
	void input(SDL_Event event);
	void render();
	void manageFps();
	void manageDropPiece();
	void addGameObj(GameObject* obj);
	void removeGameObj(int id);
	TetrisPiece* m_curr_piece;

	bool m_running;
	static GameManager* m_game_mng;
	VideoManager* m_video_mng;
	InputManager* m_input_mng;
	Timer* m_fps_timer;
	Timer* m_drop_timer;
	std::list<GameObject*> m_game_objs_list;
};

#endif /* GAMEMANAGER_H_ */
