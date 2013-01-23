/*
 * main.cpp
 *
 *  Created on: 08/04/2012
 *      Author: Vitor
 */


#include "Game/TetrisGameInstance.h"


int main(int argc, char** argv){
	TetrisGameInstance* game = new TetrisGameInstance();
	game->start();
	return 0;
}
