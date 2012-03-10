/*
 * ObjectFrame.cpp
 *
 *  Created on: 09/03/2012
 *      Author: Vitor
 */

#include "ObjectFrame.h"

void Point3::operator=(const Point3& point) {
	this->x = point.x;
	this->y = point.y;
	this->z = point.z;
}

ObjectFrame::ObjectFrame() {
	// TODO Auto-generated constructor stub

}

ObjectFrame::~ObjectFrame() {
	// TODO Auto-generated destructor stub
}

void ObjectFrame::setCenter(Point3 position) {
	m_center = position;
}

Point3 ObjectFrame::getCenter() {
	return m_center;
}


