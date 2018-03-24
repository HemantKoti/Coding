/*
 * PascalTriangle.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

vector<vector<int> > generate(int A) {
	vector<vector<int>> result;
	for (int i = 0; i < A; i++) {
		vector<int> column;
		for (int j = 0; j <= i; j++) {
			if (i == 0 || j == 0 || i == j) {
				column.push_back(1);
			} else {
				column.push_back(result[i - 1][j] + result[i - 1][j - 1]);
			}
		}
		result.push_back(column);
	}

	return result;
}

// Implementation in C
int** generate(int A, int *len1, int *len2) {
	int *result[A];
	int i, j;
	for (i = 0; i < A; i++) {
		result[i] = (int *) malloc((i + 1) * sizeof(int));
		for (j = 0; j <= i; j++) {
			if (i == 0 || j == 0 || i == j) {
				result[i][j] = 1;
			} else {
				result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
			}
		}
	}

	*len1 = *len2 = A;
	return result;
}

