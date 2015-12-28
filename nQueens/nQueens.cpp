/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void printS(const string& s)
{
	cout << s << endl;
}

void printV(const vector<string>& v)
{
	for_each(v.begin(), v.end(), printS);
	cout << endl;
}

void printM(const vector< vector<string> >& m)
{
	for_each(m.begin(), m.end(), printV);
}

//Attempting to put the Queen into [row, col], check it is valid or not
//Notes:
//  1) we just checking the Column not Row, because the row cannot be conflicted
//  2) to check the diagonal, we just check |x'-x| == |y'-y|, (x',y') is a Queen will be placed
bool isValid(int row, int col, vector<int>& queenInCol)
{
	bool valid = true;

	for (int i = 0; i < row; ++i)
	{
		if (queenInCol[i] == col)	// Col already occupied
		{
			valid = false;
		}
		else if (abs(row - i) == abs(col - queenInCol[i])) // Same diag
		{
			valid = false;
		}
	}

	return valid;
}

void solveRecursive(int n, int currentRow, vector<int>& solution, vector< vector<string> >& solutions)
{
	// Base case
	if (currentRow == n)
	{
		// Construct solution matrix
		vector<string> s;
		for (int row = 0; row < n; ++row)
		{
			string sRow;
			for (int col = 0; col < n; col++)
			{
				sRow = sRow + (solution[row] == col ? "Q" :"." );
			}
			s.push_back(sRow);
		}

		solutions.push_back(s);
		return;
	}

	for (int col = 0; col < n; ++ col)
	{
		if (isValid(currentRow, col, solution))
		{
			solution[currentRow] = col;
			solveRecursive(n, currentRow + 1, solution, solutions);
		}
	}
}

void solve(int n)
{
	vector< vector<string> > solutions;
	vector<int> queenInCol(n);

	solveRecursive(n, 0, queenInCol, solutions);

	printM(solutions);
}

int main(int argc, char **argv)
{
	int n;

	cout << "Input number of queens and return: ";
	cin >> n;

	solve(n);

	return 0;
}
