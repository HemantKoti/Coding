/*
 * AntiDiagonals.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

vector<vector<int> > diagonal(vector<vector<int> > &A) {
	vector<vector<int>> result;
	vector<int> diagonal;

	int row = A.size(), column = A[0].size();
	if (column == 0 || row == 0) {
		return result;
	}

	// Get the first row
	for (int i = 0; i < column; i++) {
		diagonal.clear();
		int p = i, q = 0;
		while (p >= 0 && q <= (row - 1)) {
			diagonal.push_back(A[q++][p--]);
		}
		result.push_back(diagonal);
	}

	// Get the last column
	for (int j = 1; j < row; j++) {
		diagonal.clear();
		int p = column - 1, q = j;
		while (p >= 0 && q <= (row - 1)) {
			diagonal.push_back(A[q++][p--]);
		}
		result.push_back(diagonal);
	}

	return result;
}

