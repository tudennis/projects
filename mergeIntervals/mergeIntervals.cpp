/*

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

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

vector<Interval> mergeIntervals(vector<Interval>& input)
{
	vector<Interval> results;

	if (input.size() > 0)
	{
		sort(input.begin(), input.end(), compareInterval);

		results.push_back(*input.begin());

		int s = input.size();

		for (int i = 1; i < s; ++i)
		{
			if (input[i].start < results.rbegin()->end
					&& input[i].end > results.rbegin()->end )
			{
				results.rbegin()->end = input[i].end;
			}
			else
			{
				results.push_back(input[i]);
			}
		}
	}

	return results;
}

int main(int argc, char ** argv)
{
	vector<Interval> input, results;
	input.push_back(Interval(1, 3));
	input.push_back(Interval(2, 6));
	input.push_back(Interval(8, 10));
	input.push_back(Interval(15, 18));

	printIntervals(input);

	results = mergeIntervals(input);

	printIntervals(results);

	return 0;
}
