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

#include "MeshComponent.h"
#include "MaterialComponent.h"
#include "../ObjectFrame.h"


class RendererComponent: public GameObjComponent {
public:
	RendererComponent();
	virtual ~RendererComponent();
	void render(const ObjectFrame& frame, MeshComponent *mesh, MaterialComponent *material = nullptr);
};

#endif /* RENDERERCOMPONENT_H_ */
