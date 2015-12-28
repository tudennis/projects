/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5].
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printCell(int cell)
{
	cout << cell << " ";
}

void printRow(const std::vector<int>& row)
{
	for_each(row.begin(), row.end(), printCell);
	cout << endl;
}

void printMatrix(const std::vector< std::vector<int> >& m)
{
	for_each(m.begin(), m.end(), printRow);
	cout << endl;
}

void spiralMatrix(const vector< vector<int> >& m)
{
	if (m.size() == 0)
	{
		return;
	}

	int rows = m.size();
	int cols = m[0].size();

	vector<int> result;

	int currentRow = 0;
	int currentCol = 0;

	while ( currentRow <= rows/2 || currentCol <= cols/2)
	{
		// 1. Top row
		for (int i = currentCol; i < cols - currentCol && currentRow < rows/2; ++ i)
		{
			result.push_back(m[currentRow][i]);
		}

		// 2. Rigt most col
		for (int i = currentRow + 1; i < rows - currentRow && currentCol < cols/2; ++ i)
		{
			result.push_back(m[i][cols - currentCol - 1]);
		}

		// 3. Bottom row reversed
		for (int i = cols - currentCol - 2; i >= currentCol && currentRow <= rows/2; --i)
		{
			result.push_back(m[rows - currentRow - 1][i]);
		}

		// 4. Left most col reversed
		for (int i = rows - currentRow - 2; i > currentRow && currentCol <= cols/2; --i)
		{
			result.push_back(m[i][currentCol]);
		}

		++ currentRow;
		++ currentCol;
	}

	printRow(result);

}

int main(int argc, char ** argv)
{
	vector< vector<int> > m;
	vector<int> row;
	row.push_back(1);
	row.push_back(2);
	row.push_back(3);
	m.push_back(row);
	row.clear();

	row.push_back(4);
	row.push_back(5);
	row.push_back(6);
	m.push_back(row);
	row.clear();

	row.push_back(7);
	row.push_back(8);
	row.push_back(9);
	m.push_back(row);
	row.clear();

	row.push_back(10);
	row.push_back(11);
	row.push_back(12);
	m.push_back(row);
	row.clear();

	row.push_back(13);
	row.push_back(14);
	row.push_back(15);
	m.push_back(row);
	row.clear();

	printMatrix(m);

	spiralMatrix(m);
	return 0;
}
