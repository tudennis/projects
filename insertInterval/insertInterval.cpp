/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval(int s, int e) : start(s), end(e) {}
};

void printInterval(const Interval& interval)
{
	cout << "[" << interval.start << ", " << interval.end << "] ";
}

void printIntervals(const vector<Interval>& intervals)
{
	for_each(intervals.begin(), intervals.end(), printInterval);
	cout << endl;
}

bool compareInterval(const Interval& l, const Interval& r)
{
	if (l.start == r.start)
		return l.end < r.end;
	else
		return l.start < r.start;
}

vector<Interval> insertMergeIntervals(vector<Interval>& input, const Interval& newInterval)
{
	vector<Interval> results;

	if (input.size() > 0)
	{
		int s = input.size();
		int i = 0;
		bool hasOverlap = false;
		for (; i < s; ++i)
		{
			if (input[i].end > newInterval.start)		// First overlapping interval
			{
				hasOverlap = true;
				break;
			}
			else
			{
				results.push_back(input[i]);
			}
		}

		if (hasOverlap)
		{
			int start = input[i].start;
			int end = input[i].end;
			while (i < s)
			{
				if (input[i].start > newInterval.end)
					break;
				end = input[i].end > newInterval.end ? input[i].end : newInterval.end;
				++ i;
			}
			results.push_back(Interval(start, end));
			while (i < s)
			{
				results.push_back(input[i]);
				++i;
			}
		}
		else
		{
			results.push_back(newInterval);
		}
	}
	else
	{
		results.push_back(newInterval);
	}

	return results;
}

int main(int argc, char** argv)
{
	vector<Interval> input, results;
	input.push_back(Interval(1, 2));
	input.push_back(Interval(3, 5));
	input.push_back(Interval(6, 7));
	input.push_back(Interval(8, 10));
	input.push_back(Interval(12, 16));

	Interval newInterval(4, 9);

	printIntervals(input);

	results = insertMergeIntervals(input, newInterval);

	printIntervals(results);
	return 0;
}
