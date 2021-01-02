/*
 * InterviewBit.h
 *
 *  Created on: Feb 5, 2018
 *      Author: HemantKo
 */

#ifndef INTERVIEWBIT_H_
#define INTERVIEWBIT_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>

using namespace std;

typedef long long LL;

#pragma region structures

class Kadan
{
public:
	int l, r, max_sum;
	Kadan()
	{
		l = r = -1;
		max_sum = INT_MIN;
	}
};

class Interval
{
public:
	int start, end;
	Interval() : start(0), end(0)
	{
	}
	Interval(int s, int e) : start(s), end(e)
	{
	}
};

class Point
{
public:
	int x, y;
};

typedef struct ListNode ListNode;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL)
	{
	}
};

#pragma endregion structures

#pragma Standard Algorithms

#pragma endregion Standard Algorithms

void SelectionSort(vector<int> &A);
void BubbleSort(vector<int> &A);
void InsertionSort(vector<int> &A);
void swap(int *a, int *b);
void MergeSort(vector<int> &A);
void QuickSort(vector<int> &A, int start, int end);
Kadan &kadan(vector<int> &arr);
double crossProduct(Point a, Point b);
Point transformCoordinates(Point b, Point a);

#pragma region Arrays

vector<int> spiralOrder(const vector<vector<int>> &A);
int overPoints(vector<int> &A, vector<int> &B);
vector<int> plusOne(vector<int> &A);
int maxSubArray(const vector<int> &A);
int maxArr(vector<int> &A);
vector<int> repeatedNumber(const vector<int> &A);
vector<int> flip(string A);
vector<int> maxset(vector<int> &A);
vector<vector<int>> generateMatrix(int A);
vector<vector<int>> generate(int A);
int **generate(int A, int *len1, int *len2);
vector<vector<int>> diagonal(vector<vector<int>> &A);
int solve(vector<int> &A);
vector<int> wave(vector<int> &A);
int findDuplicateInArray(const vector<int> &A);
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);
vector<Interval> merge(vector<Interval> &A);
string largestNumber(const vector<int> &A);
int firstMissingPositive(vector<int> &A);
string largeFactorial(int A);

#pragma endregion Arrays

#pragma region Math

vector<int> allFactors(int A);
string findDigitsInBinary(int A);
vector<int> sieve(int A);
int isPrime(int A);
int isPalindrome(int A);
int reverse(int A);
int gcd(int A, int B);
int trailingZeroes(int A);
vector<string> fizzBuzz(int A);
int titleToNumber(string A);
string convertToTitle(int A);
uint64_t choose(int n, int r);
int uniquePaths(int A, int B);
void arrange(vector<int> &A);
string decimalToBinary(int A);
double areaOfPolygon(vector<Point> points);
int getDirection(Point a, Point b, Point c);
int solve(vector<int> &A, int B, int C);

#pragma endregion Math

#pragma region Binary Search

int findCount(const vector<int> &A, int B);
int binarySearch(vector<int> &A, int element);
int findMin(const vector<int> &A);
int pow(int x, int n, int d);
int sqrt(int A);
int searchInsert(vector<int> &A, int B);
vector<int> searchRange(const vector<int> &A, int B);
int search(const vector<int> &A, int B);
double findMedianSortedArrays(const vector<int> &A, const vector<int> &B);
int paint(int A, int B, vector<int> &C);

#pragma endregion Binary Search

#pragma region Recursion

int factorial(int n);
int fibonacci(int n);
long long power(long long x, int n);
long long modularExponentiation(long long x, int n, int m);

#pragma endregion Recursion

#pragma region Bit Manipulation

bool checkIfKthBitIsSet(unsigned A, int K);
unsigned setKthBit(unsigned A, int K);
unsigned clearKthBit(unsigned A, int K);
unsigned toggleKthBit(unsigned A, int K);
unsigned getTwosComplement(unsigned A);
unsigned isolateRightMostOneBit(unsigned A);
unsigned isolateRightMostZeroBit(unsigned A);
bool checkIfPowerOfTwo(unsigned A);
int numSetBits(unsigned int A);
unsigned reverse(unsigned int A);

#pragma endregion Bit Manipulation

#pragma region Two Pointers

void merge(vector<int> &A, vector<int> &B);
vector<int> intersect(const vector<int> &A, const vector<int> &B);
int removeDuplicates(vector<int> &A);
int removeDuplicatesII(vector<int> &A);
int removeElement(vector<int> &A, int B);

#pragma endregion Two Pointers

#pragma region Linked List

ListNode *createNewNode(int data);
void insertInTheBeginning(ListNode **headPtr, int data);
void insertAfter(ListNode **headPtr, int data);
void insertInTheEnd(ListNode **headPtr, int data);
void deleteNodeKey(ListNode **headPtr, int data);
void deleteNodePosition(ListNode **headPtr, int data);
void deleteList(ListNode *head);
void printList(ListNode *head);
int linkedListLengthIterative(ListNode *head);
int linkedListLengthRecursive(ListNode *head);
bool searchElementInListIterative(ListNode *head, int data);
bool searchElementInListRecursive(ListNode *head, int data);
ListNode *getNthNodeLinkedList(ListNode *head, int position);
ListNode *getNthNodeFromEndLinkedList(ListNode *head, int position);
void reverseLinkedList(ListNode **headPtr);
ListNode *getMiddle(ListNode *head);
void swapNodes(ListNode **headPtr, int x, int y);
int countLoopNodes(ListNode *head);
ListNode *detectCycle(ListNode *head);
ListNode *getIntersectionNode(ListNode *A, ListNode *B);
ListNode *reverseBetween(ListNode *head, int B, int C);
ListNode *reorderList(ListNode *head);
ListNode *deleteDuplicates(ListNode *A);
ListNode *deleteDuplicatesII(ListNode *A);
ListNode *rotateRight(ListNode *A, int B);
int listLength(ListNode *head);
ListNode *removeNthFromEnd(ListNode *A, int B);
ListNode *swapPairs(ListNode *A);
int lPalin(ListNode *A);

#pragma endregion Linked List

#pragma region Strings

string findPhoneNumber(string str);

#pragma endregion Strings

#endif /* INTERVIEWBIT_H_ */
