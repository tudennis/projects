/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
void printVal(const T& val)
{
	cout << val << " ";
}

template <typename T>
void printRow(const vector<T>& row)
{
	for_each(row.begin(), row.end(), printVal<T>);
	cout << endl;
}

template <typename T>
void printMatrix(const vector< vector<T> >& matrix)
{
	for_each(matrix.begin(), matrix.end(), printRow<T>);
	cout << endl;
}

int largestRectangle(vector<int>& histogram)
{
	int size = histogram.size();

	vector<int> s;
	histogram.push_back(0);	// Flag to force poping out all items in stack

	int result(0);

	for (int i = 0; i < size; ++ i)
	{
		if (s.size() == 0 || histogram[i] >= histogram[s.back()])
		{
			s.push_back(i);			// The index
		}
		else
		{
			int temp = s.back();
			s.pop_back();
			int tempResult = histogram[temp] * (s.size() == 0 ? i : i - s.back() - 1);
			result = max(tempResult, result);
			-- i; // Do it again, make it popping until we can push it into the stack
		}
	}

	return result;
}

int main(int argc, char ** argv)
{
	vector<int> histogram;
	histogram.push_back(2);
	histogram.push_back(1);
	histogram.push_back(5);
	histogram.push_back(6);
	histogram.push_back(2);
	histogram.push_back(3);

	printRow<int>(histogram);
	int result = largestRectangle(histogram);
	cout << "Largest rectangle: " << result << endl;

	return 0;
}
