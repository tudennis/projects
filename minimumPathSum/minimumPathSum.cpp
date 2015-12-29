/*
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
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

void populate(vector< vector<int> >& matrix)
{
	vector<int> row;
	row.push_back(2);
	row.push_back(5);
	row.push_back(7);
	row.push_back(1);
	matrix.push_back(row);

	row.clear();
	row.push_back(3);
	row.push_back(9);
	row.push_back(1);
	row.push_back(4);
	matrix.push_back(row);

	row.clear();
	row.push_back(5);
	row.push_back(1);
	row.push_back(6);
	row.push_back(7);
	matrix.push_back(row);

	row.clear();
	row.push_back(3);
	row.push_back(4);
	row.push_back(4);
	row.push_back(7);
	matrix.push_back(row);

	row.clear();
	row.push_back(7);
	row.push_back(3);
	row.push_back(5);
	row.push_back(8);
	matrix.push_back(row);

	row.clear();
	row.push_back(2);
	row.push_back(8);
	row.push_back(8);
	row.push_back(3);
	matrix.push_back(row);
}

void minimumPathSum(const vector< vector<int> >& matrix)
{
	if (matrix.size() <= 0)
	{
		return;
	}

	int rows = matrix.size();
	int cols = matrix[0].size();

	vector< vector<int> > paths;

	// Init matrix
	vector<int> row;
	for (int i = 0; i < cols; ++ i)
	{
		row.push_back(0);
	}
	for (int i = 0; i < rows; ++ i)
	{
		paths.push_back(row);
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (i == 0 && j == 0)
			{
				paths[i][j] = matrix[i][j];
			}
			else if (i == 0)
			{
				paths[i][j] = paths[i][j - 1] + matrix[i][j];
			}
			else if (j == 0)
			{
				paths[i][j] = paths[i - 1][j] + matrix[i][j];
			}
			else
			{
				paths[i][j] = min(paths[i-1][j], paths[i][j-1]) + matrix[i][j];
			}
		}
	}

	printMatrix(paths);

	// Back trace to get the path
	int sum = paths[rows - 1][cols - 1];
	int r = rows - 1;
	int c = cols - 1;
	cout << r << ", " << c << endl;
	while (sum - matrix[r][c] > 0)
	{
		sum -= matrix[r][c];
		if (sum == paths[r-1][c])
		{
			cout << r-1 << ", " << c << endl;
			--r;
		}
		else
		{
			cout << r << ", " << c-1 << endl;
			--c;
		}
	}
}

int main(int argc, char ** argv)
{
	vector< vector<int> > matrix;

	populate(matrix);
	printMatrix(matrix);

	minimumPathSum(matrix);

	return 0;
}
