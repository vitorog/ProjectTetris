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

int main(int argc, char** argv)
{
	GameManager* gm = GameManager::getInstance();
	gm->run();
	return 0;
}




