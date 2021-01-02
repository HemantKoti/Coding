/*
 * MergeIntervals.cpp
 *
 *  Created on: Mar 19, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

bool doesIntersect(Interval a, Interval b)
{
	if (min(a.end, b.end) < max(a.start, b.start))
		return false;
	return true;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
	vector<Interval> result;

	// Return newInterval if 0 elements are present
	if (intervals.size() == 0)
	{
		result.push_back(newInterval);
		return result;
	}

	int size = intervals.size();
	// If the newInterval lies in front/end of the list
	if (newInterval.end < intervals[0].start || newInterval.start > intervals[size - 1].end)
	{
		if (newInterval.end < intervals[0].start)
		{
			result.push_back(newInterval);
		}
		for (int i = 0; i < intervals.size(); i++)
		{
			result.push_back(intervals[i]);
		}
		if (newInterval.start > intervals[size - 1].end)
		{
			result.push_back(newInterval);
		}
		return result;
	}

	for (int i = 0; i < intervals.size(); i++)
	{
		bool intersect = doesIntersect(intervals[i], newInterval);
		if (!intersect)
		{
			result.push_back(intervals[i]);
			// Check if the newInterval lies between interval[i] and interval[i+1]
			if (i < size - 1 && newInterval.start > intervals[i].end && newInterval.end < intervals[i].start)
			{
				result.push_back(newInterval);
			}
			continue;
		}

		// Check to what range the overlap exists
		int si = i; // Store the start interval
		while (i < size && intersect)
		{
			i++;
			intersect = (i == size) ? false : doesIntersect(intervals[i], newInterval);
		}
		i--;

		// Push the merged interval to result
		Interval merged(min(newInterval.start, intervals[si].start), max(newInterval.end, intervals[i].end));
		result.push_back(merged);
	}
	return result;
}
