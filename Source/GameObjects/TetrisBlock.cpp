/*
 * TetrisBlock.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#include "TetrisBlock.h"

TetrisBlock::TetrisBlock(Point3 position, Point3 color) {
	m_center = position;
	m_color = color;
}

TetrisBlock::~TetrisBlock() {
	// TODO Auto-generated destructor stub
}

