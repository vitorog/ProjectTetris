/*
 * RendererComponent.h
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#pragma once
#ifndef RENDERERCOMPONENT_H_
#define RENDERERCOMPONENT_H_

#include "Components/GameObjComponent.h"
#include "utils.h"
class MeshComponent;
class MaterialComponent;
class ObjectFrame;

class RendererComponent: public GameObjComponent {
public:
	RendererComponent();
	virtual ~RendererComponent();
	void render(const ObjectFrame& frame, MeshComponent *mesh, MaterialComponent *material = nullptr);
};

#endif /* RENDERERCOMPONENT_H_ */
