/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
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

void populateMatrix(vector< vector<int> >& matrix)
{
	vector<int> row;

	row.clear();
	row.push_back(0);
	row.push_back(0);
	row.push_back(1);
	row.push_back(1);
	matrix.push_back(row);

	row.clear();
	row.push_back(1);
	row.push_back(0);
	row.push_back(1);
	row.push_back(1);
	matrix.push_back(row);

	row.clear();
	row.push_back(0);
	row.push_back(1);
	row.push_back(1);
	row.push_back(1);
	matrix.push_back(row);
}

int largestRectangleInHistogram(vector<int>& histogram)
{
	printRow<int>(histogram);

	vector<int> stack;
	histogram.push_back(0); // Fake end

	int size = histogram.size();
	int result(0);

	for (int i = 0; i < size; ++i)
	{
		if (stack.size() == 0 || histogram[i] >= histogram[stack.back()])		// Push into stack
		{
			stack.push_back(i);		// Index
		}
		else				// Start poping out all previous that's larger than the new one
		{
			int idx = stack.back();
			stack.pop_back();

			int newRectangle = histogram[idx] * (stack.size() == 0 ?  i : i - histogram[stack.back()] - 1);
			if (newRectangle > result)
			{
				result = newRectangle;
			}
			-- i;	// Do this till all the previous larger ones are not in the stack anymore
		}
	}

	return result;
}

int maximalRectangle(vector< vector<int> >& matrix)
{
	if (matrix.size() <= 0)
	{
		return 0;
	}

	int rows = matrix.size();
	int cols = matrix[0].size();

	vector< vector<int> > histogram(rows, vector<int>(cols, 0));

	int result(0);

	// Populate histogram matrix, and calculate the largest rectangle row by row
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (i == 0)
			{
				histogram[i][j] = matrix[i][j];
			}
			else
			{
				if (matrix[i][j] == 1)
				{
					histogram[i][j] = histogram[i - 1][j] + 1;
				}
			}
		}

		int r = largestRectangleInHistogram(histogram[i]);
		if (r > result)
		{
			result = r;
		}
	}

	return result;
}

int main(int argc, char ** argv)
{
	vector< vector<int> > matrix;
	populateMatrix(matrix);

	printMatrix(matrix);

	cout << "maximal rectangle: " << maximalRectangle(matrix) << endl;

	return 0;
}
