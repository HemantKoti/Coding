/*
 * SpiralOrderMatrixII.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

vector<vector<int> > generateMatrix(int A) {
	vector<vector<int> > result(A, vector<int>(A));
	enum Directions {
		LEFT_TO_RIGHT, TOP_TO_BOTTOM, RIGHT_TO_LEFT, BOTTOM_TO_TOP
	};
	int direction = LEFT_TO_RIGHT;
	int top = 0, left = 0, right = A - 1, bottom = A - 1, count = 0;
	while (count < A * A) {
		if (direction == LEFT_TO_RIGHT) {
			for (int i = left; i <= right; i++) {
				result[top][i] = ++count;
			}
			top++;
			direction = TOP_TO_BOTTOM;
		} else if (direction == TOP_TO_BOTTOM) {
			for (int i = top; i <= bottom; i++) {
				result[i][right] = ++count;
			}
			right--;
			direction = RIGHT_TO_LEFT;
		} else if (direction == RIGHT_TO_LEFT) {
			for (int i = right; i >= left; i--) {
				result[bottom][i] = ++count;
			}
			bottom--;
			direction = BOTTOM_TO_TOP;
		} else if (direction == BOTTOM_TO_TOP) {
			for (int i = bottom; i >= top; i--) {
				result[i][left] = ++count;
			}
			left++;
			direction = LEFT_TO_RIGHT;
		}
	}

	return result;
}

