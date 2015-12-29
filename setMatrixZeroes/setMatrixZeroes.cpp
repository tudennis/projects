/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
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

void setZeroes(vector< vector<int> >& matrix)
{
	if (matrix.size() <= 0)
	{
		return;
	}

	int rows = matrix.size();
	int cols = matrix[0].size();

	bool bRow(false), bCol(false);

	for (int i = 0; i < rows; ++ i)
	{
		for (int j = 0; j< cols; ++j)
		{
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = matrix[i][0] = 0;
				if (i == 0) bRow = true;
				if (j == 0) bRow = true;
			}
		}
	}

	for (int i = 1; i < rows; ++ i)
	{
		for (int j = 1; j < cols; ++j)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
			{
				matrix[i][j] = 0;
			}
		}
	}

	if (bRow)
	{
		for (int i = 0; i < cols; ++i)
			matrix[0][i] = 0;
	}

	if (bCol)
	{
		for (int i = 0; i < rows; ++i)
			matrix[i][0] = 0;
	}
}

void populateMatrix(vector< vector<int> >& matrix)
{
	vector<int> row;
	row.clear();
	row.push_back(1);
	row.push_back(0);
	row.push_back(1);
	row.push_back(0);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	matrix.push_back(row);

	row.clear();
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	matrix.push_back(row);

	row.clear();
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(0);
	matrix.push_back(row);

	row.clear();
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	matrix.push_back(row);

	row.clear();
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	matrix.push_back(row);
}

int main(int argc, char **argv)
{
	//vector< vector<int> > matrix(5, vector<int>(7)); // This will create matrix 5*7 and init to all 0s.

	vector< vector<int> > matrix;

	populateMatrix(matrix);
	printMatrix(matrix);

	setZeroes(matrix);
	printMatrix(matrix);

	return 0;
}
