/*
 * BoundingBox2d.h
 *
 *  Created on: 11/03/2012
 *      Author: Vitor
 */

#ifndef BOUNDINGBOX2D_H_
#define BOUNDINGBOX2D_H_

#include "utils.h"

typedef enum BoundaryPoint_t{ LOWER_LEFT = 0, LOWER_RIGHT, UPPER_RIGHT, UPPER_LEFT }BoundaryPoint;

class BoundingBox2d
{
public:
		BoundingBox2d() = default;
		virtual ~BoundingBox2d();
		void setBoundaries(glm::vec3 center, float width, float height);
		bool isPointInside(glm::vec3 point);
		glm::vec3 getCenter();
		glm::vec3 getBorderPoint(int pos);
private:
		std::vector<glm::vec3> m_boundaries;
		glm::vec3 m_center;
		float m_size;
};

#endif /* BOUNDINGBOX2D_H_ */
