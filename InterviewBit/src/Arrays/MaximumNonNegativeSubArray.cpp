/*
 * MaximumNonNegativeSubArray.cpp
 *
 *  Created on: Feb 24, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

class MaxSet
{
public:
	vector<int> values;
	LL max_sum;
	MaxSet()
	{
		values.clear();
		max_sum = LONG_MIN;
	}
};

vector<int> maxset(vector<int> &A)
{
	// Use long long to avoid overflow
	vector<MaxSet> segments;
	MaxSet segment;
	LL best_till_now = 0;

	// Add the segments to a vector
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] < 0)
		{
			segments.push_back(segment);
			best_till_now = 0;
			segment = MaxSet();
		}
		else
		{
			segment.values.push_back(A[i]);
			best_till_now += A[i];
		}
		segment.max_sum = max(best_till_now, segment.max_sum);
	}

	// Add the last segment to the vector
	segments.push_back(segment);

	// Compare each segment with the other
	vector<int> result;
	LL maximum = LONG_MIN;
	int idx = 0;
	for (int i = 0; i < segments.size(); i++)
	{
		// Get the maximum segment and store its index
		if (maximum < segments[i].max_sum)
		{
			maximum = segments[i].max_sum;
			result = segments[i].values;
			idx = i;
		}
		// If there are 2 maximums, get the one with the higher size
		else if (maximum == segments[i].max_sum)
		{
			result = segments[idx].values.size() < segments[i].values.size() ? segments[i].values : result;
		}
	}

	return result;
}
