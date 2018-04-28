/*
 * AreaOfPolygon.cpp
 *
 *  Created on: Apr 29, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

double crossProduct(Point a, Point b) {
	return a.x * b.y - b.x * a.y;
}

double areaOfPolygon(vector<Point> points) {
	double sum = 0.0;
	for (int i = 0; i < points.size(); i++) {
		sum += crossProduct(points[i], points[(i + 1) % points.size()]);
	}
	return abs(sum / 2); // If the sum is positive, the direction of the line perpendicular to A & B is counter clockwise. If negative, it is clockwise.
}

