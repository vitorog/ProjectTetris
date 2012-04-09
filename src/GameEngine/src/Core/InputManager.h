/*
 * InputManager.h
 *
 *  Created on: 10/03/2012
 *      Author: Vitor
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include <SDL/SDL.h>

#include <set>
#include <string>

extern SDL_Event input_event;

class InputManager {
public:
	virtual ~InputManager();
	void handleInput(SDL_Event event);
	bool checkKey(std::string key);
	bool checkQuitApp();
	static InputManager* getInstance();
private:
	InputManager();
	void handleKeyPresses(SDL_Event event);
	void handleKeyReleases(SDL_Event event);
	static InputManager* m_input_mng_ptr;
	std::set<std::string> m_keys_set;
	bool m_quit;
	bool m_disable_key_hold;

};

#endif /* INPUTMANAGER_H_ */
