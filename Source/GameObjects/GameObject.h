/*
 * GameObject.h
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "../Components/GameObjComponent.h"
#include "../Components/RendererComponent.h"

#include <list>
#include <map>

typedef enum TetrisPieceType_t {
	TETRIS_SQUARE_PIECE = 0,
	TETRIS_LINE_PIECE,
	TETRIS_S_PIECE,
	TETRIS_Z_PIECE,
	TETRIS_L_PIECE,
	TETRIS_J_PIECE,
	TETRIS_T_PIECE
}TetrisPieceType;

class Point3
{
public:
	Point3(){
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}
	float x;
	float y;
	float z;
	void operator=(const Point3& point);
};

class GameObject {
public:
	GameObject();
	virtual ~GameObject();
	void addComponent(GameObjComponent* component);
	void addChild(GameObject* obj);
	void render();
	GameObjComponent* get_component(ComponentType type);
	bool has_children();
	std::list<GameObject*> m_children;
	std::map<ComponentType, GameObjComponent*> m_components;
	Point3 m_center;
	Point3 m_color;
};

#endif /* GAMEOBJECT_H_ */
