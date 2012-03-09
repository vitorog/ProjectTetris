/*
 * RendererComponent.h
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#ifndef RENDERERCOMPONENT_H_
#define RENDERERCOMPONENT_H_

#include "../Managers/VideoManager.h"
#include "GameObjComponent.h"

class RendererComponent: public GameObjComponent {
public:
	RendererComponent();
	virtual ~RendererComponent();
	void render();
};

#endif /* RENDERERCOMPONENT_H_ */
