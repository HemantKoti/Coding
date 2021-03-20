/*
 * VectorAlgebra.cpp
 *
 *  Created on: Apr 29, 2018
 *      Author: HemantKo
 */

#include "../include/global.h"

double crossProduct(Point a, Point b)
{
	return a.x * b.y - b.x * a.y;
}

Point transformCoordinates(Point b, Point a)
{
	Point result;
	result.x = b.x - a.x;
	result.y = b.y - a.y;
	return result;
}
