/*
 * RendererComponent.h
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#ifndef RENDERERCOMPONENT_H_
#define RENDERERCOMPONENT_H_

#include "../GameObjects/GameObject.h"
#include "../Managers/VideoManager.h"
#include "GameObjComponent.h"

class Point3;

class RendererComponent: public GameObjComponent {
public:
	RendererComponent();
	virtual ~RendererComponent();

	void render(Point3 center, float size, Point3 color);
};

#endif /* RENDERERCOMPONENT_H_ */
