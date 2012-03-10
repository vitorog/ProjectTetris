/*
 * ObjectFrame.h
 *
 *  Created on: 09/03/2012
 *      Author: Vitor
 */

#ifndef OBJECTFRAME_H_
#define OBJECTFRAME_H_


class Point3
{
public:
	Point3(){
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}
	float x;
	float y;
	float z;
	void operator=(const Point3& point);
};


class ObjectFrame {
public:
	ObjectFrame();
	virtual ~ObjectFrame();
	void setCenter(Point3 position);
	Point3 getCenter();
private:
	Point3 m_center;
};

#endif /* OBJECTFRAME_H_ */
