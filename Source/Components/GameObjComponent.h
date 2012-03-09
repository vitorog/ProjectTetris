/*
 * GameObjComponent.h
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#ifndef GAMEOBJCOMPONENT_H_
#define GAMEOBJCOMPONENT_H_

typedef enum ComponentType_t { RENDERER_COMPONENT = 0 }ComponentType;

class GameObjComponent {
public:
	GameObjComponent();
	virtual ~GameObjComponent();
};

#endif /* GAMEOBJCOMPONENT_H_ */
