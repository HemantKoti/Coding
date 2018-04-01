/*
 * InterviewBit.h
 *
 *  Created on: Feb 5, 2018
 *      Author: HemantKo
 */

#ifndef INTERVIEWBIT_H_
#define INTERVIEWBIT_H_

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#pragma region structures

class Kadan {
public:
	int l;
	int r;
	int max_sum;
	Kadan() {
		l = r = -1;
		max_sum = INT_MIN;
	}
};

struct Interval {
	int start;
	int end;
	Interval() :
			start(0), end(0) {
	}
	Interval(int s, int e) :
			start(s), end(e) {
	}
};

#pragma endregion structures

#pragma region Arrays

vector<int> spiralOrder(const vector<vector<int> > &A);
int overPoints(vector<int> &A, vector<int> &B);
vector<int> plusOne(vector<int> &A);
int maxSubArray(const vector<int> &A);
int maxArr(vector<int> &A);
vector<int> repeatedNumber(const vector<int> &A);
vector<int> flip(string A);
Kadan& kadan(vector<int> &arr);
vector<int> maxset(vector<int> &A);
vector<vector<int> > generateMatrix(int A);
vector<vector<int> > generate(int A);
int ** generate(int A, int *len1, int *len2);
vector<vector<int> > diagonal(vector<vector<int> > &A);
int solve(vector<int> &A);
vector<int> wave(vector<int> &A);
int findDuplicateInArray(const vector<int> &A);
void SelectionSort(vector<int> &A);
void BubbleSort(vector<int> &A);
void InsertionSort(vector<int> &A);
void swap(int *a, int *b);
void MergeSort(vector<int> &A);
void QuickSort(vector<int> &A, int start, int end);
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);
vector<Interval> merge(vector<Interval> &A);
string largestNumber(const vector<int> &A);
int firstMissingPositive(vector<int> &A);

#pragma endregion Arrays

#pragma region Math

vector<int> allFactors(int A);
string findDigitsInBinary(int A);
vector<int> sieve(int A);
int isPrime(int A);
int isPalindrome(int A);
int reverse(int A);

#pragma endregion Math

#endif /* INTERVIEWBIT_H_ */
