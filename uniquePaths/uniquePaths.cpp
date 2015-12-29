/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100

*/

/*

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

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

void uniquePaths(int rows, int cols)
{
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

	for (int i = 0; i < rows; ++ i)
	{
		for (int j = 0; j < cols; ++ j)
		{
			if (i == 0 || j == 0)
			{
				paths[i][j] = 1;
			}
			else
			{
				paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
			}
		}
	}

	printMatrix(paths);
}

void uniquePathsII(int rows, int cols)
{
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

	paths[2][5] = -1; 	// Indicate the obstacle

	printMatrix(paths);

	for (int i = 0; i < rows; ++ i)
	{
		for (int j = 0; j < cols; ++ j)
		{
			if (i == 0 && j == 0)
			{
				paths[i][j] = 1;		// Start position can't be negative
			}
			else if (paths[i][j] < 0)	// Obstacle ignore
			{
				// Nothing to do
			}
			else
			{
				if (i == 0)
				{
					paths[i][j] = paths[i][j - 1] < 0 ? -1 : paths[i][j - 1];
				}
				else if (j == 0)
				{
					paths[i][j] = paths[i - 1][j] < 0 ? -1 : paths[i - 1][j];
				}
				else
				{
					if (paths[i - 1][j] < 0 && paths[i][j - 1] < 0)
					{
						paths[i][j] = -1;
					}
					else
					{
						if (paths[i - 1][j] < 0)
						{
							paths[i][j] = paths[i][j - 1];
						}
						else if (paths[i][j - 1] < 0)
						{
							paths[i][j] = paths[i - 1][j];
						}
						else
						{
							paths[i][j] =  paths[i - 1][j] + paths[i][j - 1];
						}
					}
				}
			}
		}
	}

	printMatrix(paths);
}

int main(int argc, char ** argv)
{
	uniquePaths(3, 7);

	uniquePathsII(3, 7);

	return 0;
}
