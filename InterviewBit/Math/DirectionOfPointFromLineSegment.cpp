/*
 * DirectionOfPointFromLineSegment.cpp
 *
 *  Created on: Apr 29, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

Point transformCoordinates(Point b, Point a) {
	Point result;
	result.x = b.x - a.x;
	result.y = b.y - a.y;
	return result;
}

int getDirection(Point a, Point b, Point c) {
	enum Direction {
		LEFT, RIGHT, ON_THE_LINE
	};

	int direction = ON_THE_LINE;
	b = transformCoordinates(b, a);
	c = transformCoordinates(c, a);
	double result = crossProduct(b, c);

	if (result > 0)
		direction = LEFT;
	else if (result < 0)
		direction = RIGHT;
	else
		direction = ON_THE_LINE;

	return direction;
}

