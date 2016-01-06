/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may
move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

#include <iostream>
#include <vector>
#include <algorithm>
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

int minimumPathSumHelper(vector< vector<int> >& input, int row, int col, vector<int>& result)
{
	vector<int>& r = input[row];
	if (row == input.size() - 1)
	{
		return min(r[col], r[col + 1]);
	}

	int left = minimumPathSumHelper(input, row + 1, col, result);
	int right = minimumPathSumHelper(input, row + 1, col + 1, result);

	if (left <= right)
	{
		result.push_back(input[row + 1][col]);
		return left + input[row][col];
	}
	else
	{
		result.push_back(input[row + 1][col + 1]);
		return right + input[row][col];
	}
}

vector<int> minimumPathSum(vector< vector<int> >& input)
{
	vector<int> result;
	if (input.size() == 0)
	{
		return result;
	}

	result.push_back(input[0][0]);
	int sum = minimumPathSumHelper(input, 1, 0, result);

	cout << "Minimum path sum: " << sum << endl;

	return result;
}

int main(int argc, char ** argv)
{
	vector< vector<int> > input;
	vector<int> row;
	row.clear();
	row.push_back(2);
	input.push_back(row);

	row.clear();
	row.push_back(3);
	row.push_back(4);
	input.push_back(row);

	row.clear();
	row.push_back(6);
	row.push_back(5);
	row.push_back(7);
	input.push_back(row);

	row.clear();
	row.push_back(4);
	row.push_back(1);
	row.push_back(8);
	row.push_back(3);
	input.push_back(row);

	printMatrix(input);

	vector<int> result = minimumPathSum(input);

	printRow(result);

	return 0;
}
