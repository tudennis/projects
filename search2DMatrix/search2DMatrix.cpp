/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printVal(const int val)
{
	cout << val << " ";
}

void printRow(const vector<int>& row)
{
	for_each(row.begin(), row.end(), printVal);
	cout << endl;
}

void printMatrix(const vector< vector<int> >& matrix)
{
	for_each(matrix.begin(), matrix.end(), printRow);
	cout << endl;
}

void populateMatrix(vector< vector<int> >& matrix)
{
	vector<int> row;
	row.clear();
	row.push_back(1);
	row.push_back(3);
	row.push_back(5);
	row.push_back(7);
	matrix.push_back(row);

	row.clear();
	row.push_back(10);
	row.push_back(11);
	row.push_back(16);
	row.push_back(20);
	matrix.push_back(row);

	row.clear();
	row.push_back(23);
	row.push_back(30);
	row.push_back(34);
	row.push_back(50);
	matrix.push_back(row);
}

bool searchMatrix(const vector< vector<int> >& matrix, int target)
{
	if (matrix.size() == 0)
	{
		return false;
	}

	int rows = matrix.size();
	int cols = matrix[0].size();

	int low = 0;
	int high = rows * cols - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		int r = mid / rows;
		int c = mid % rows;

		cout << r << ", " << c << endl;

		if (target == matrix[r][c])
		{
			return true;
		}
		else
		{
			if (target > matrix[r][c])
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}

		}
	}


	return false;
}


int main(int argc, char ** argv)
{
	vector< vector<int> > matrix;

	populateMatrix(matrix);
	printMatrix(matrix);

	bool find = searchMatrix(matrix, 3);

	cout << "Result: " << find << endl;

	return 0;
}
