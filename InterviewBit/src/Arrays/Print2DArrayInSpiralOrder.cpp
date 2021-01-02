/*
 * Print2DArrayInSpiralOrder.cpp
 *
 *  Created on: Feb 5, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

vector<int> spiralOrder(const vector<vector<int>> &A)
{
	enum Direction
	{
		LEFT_TO_RIGHT = 0,
		TOP_TO_BOTTOM = 1,
		RIGHT_TO_LEFT = 2,
		BOTTOM_TO_UP = 3
	};

	int direction = LEFT_TO_RIGHT;
	int top = 0, bottom = A.size() - 1, left = 0, right = A[0].size() - 1;
	vector<int> spiral;

	while (top <= bottom && left <= right)
	{
		if (direction == LEFT_TO_RIGHT)
		{
			for (int i = left; i <= right; i++)
			{
				spiral.push_back(A[top][i]);
			}
			direction = TOP_TO_BOTTOM;
			top++;
		}
		else if (direction == TOP_TO_BOTTOM)
		{
			for (int i = top; i <= bottom; i++)
			{
				spiral.push_back(A[i][right]);
			}
			direction = RIGHT_TO_LEFT;
			right--;
		}
		else if (direction == RIGHT_TO_LEFT)
		{
			for (int i = right; i >= left; i--)
			{
				spiral.push_back(A[bottom][i]);
			}
			direction = BOTTOM_TO_UP;
			bottom--;
		}
		else if (direction == BOTTOM_TO_UP)
		{
			for (int i = bottom; i >= top; i--)
			{
				spiral.push_back(A[i][left]);
			}
			direction = LEFT_TO_RIGHT;
			left++;
		}
	}

	return spiral;
}
