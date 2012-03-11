/*
 * main.cpp
 *
 *  Created on: 06/03/2012
 *      Author: Vitor
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Managers/VideoManager.h"
#include "Managers/GameManager.h"

#include "ObjectFrame.h"

int main(int argc, char** argv)
{
	ObjectFrame *fm = new ObjectFrame();
	fm->setCenter(glm::vec3(1.0f,0.0f,0.0f));
	glm::vec3 center = fm->getCenter();
	std::cout << center.x << " " << center.y << " " << center.z << std::endl;

	fm->translate(glm::vec3(5.0f,0.0f,0.0f));
	center = fm->getCenter();
	std::cout << center.x << " " << center.y << " " << center.z << std::endl;

	fm->rotate(90,glm::vec3(0.0f,0.0f,1.0f));
	center = fm->getCenter();
	std::cout << center.x << " " << center.y << " " << center.z << std::endl;


	delete fm;

	GameManager* gm = GameManager::getInstance();
	gm->run();
	std::cout << "TESTE" << std::endl;
	return 0;
}




