/*
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

*/

/*
思路：目标是要找到由X包围起来的O的区域。

首先，外围一圈上的O肯定会保留下来。然后，从外围的O能达到的O也要保留。剩下其他的O就是内部的O。

所以方法就是从外围的一圈进行DFS算法：依次对外圈的“O”做DFS，将其可以到达O临时设置为#。

特殊用例：只有外围轮廓没有内部。比如长或者宽小于2，此时不存在被包围的'X'。
 */

#include <vector>
#include <algorithm>
#include <iostream>
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

void populateBoard(vector< vector<char> >& matrix)
{
	vector<char> row;

	row.clear();
	row.push_back('X');
	row.push_back('X');
	row.push_back('X');
	row.push_back('X');
	matrix.push_back(row);

	row.clear();
	row.push_back('X');
	row.push_back('O');
	row.push_back('O');
	row.push_back('X');
	matrix.push_back(row);

	row.clear();
	row.push_back('X');
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	matrix.push_back(row);

	row.clear();
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('X');
	matrix.push_back(row);
}

void dfs(int r, int c, int row, int col, vector< vector<char> >& board)
{
	if (board[r][c] == 'O')
	{
		board[r][c] = 'S';
		if (r > 0 && board[r - 1][c] == 'O')		// Up
		{
			board[r - 1][c] = 'S';
			dfs(r - 1, c, row, col, board);
		}

		if (c < col - 1 && board[r][c + 1] == 'O')	// Right
		{
			board[r][c + 1] = 'S';
			dfs(r, c + 1, row, col, board);
		}

		if (r < row - 1 && board[r + 1][c] == 'O')	// Down
		{
			board[r + 1][c] = 'S';
			dfs(r + 1, c, row, col, board);
		}

		if (c > 0 && board[r][c - 1] == 'O')		// Left
		{
			board[r][c - 1] = 'S';
			dfs(r, c - 1, row, col, board);
		}
	}
}

void boarderDFS(vector< vector<char> >& board)
{
	int row = board.size();
	if (row == 0)
		return;

	int col = board[0].size();
	if (col == 0)
		return;

	for (int i = 0; i < col; ++i)		// First row
	{
		dfs(0, i, row, col, board);
	}

	for (int i = 1; i < row; ++i)		// Last col - top cell
	{
		dfs(i, col - 1, row, col, board);
	}

	for (int i = 0; i < col - 1; ++i)	// Last row - last cell
	{
		dfs(row - 1, i, row, col, board);
	}

	for (int i = 1; i < row - 1; ++i)	// First col - first cell - last cell
	{
		dfs(i, 0, row, col, board);
	}
}

void replaceBoard(vector< vector<char> >& board)
{
	int row = board.size();
	if (row == 0)
		return;

	int col = board[0].size();
	if (col == 0)
		return;

	for (int r = 0; r < row; ++ r)
	{
		for (int c = 0; c < col; ++ c)
		{
			if (board[r][c] == 'O')
			{
				board[r][c] = 'X';
			}
		}
	}

	for (int r = 0; r < row; ++ r)
	{
		for (int c = 0; c < col; ++ c)
		{
			if (board[r][c] == 'S')
			{
				board[r][c] = 'O';
			}
		}
	}
}

int main(int argc, char ** argv)
{
	vector< vector<char> > board;
	populateBoard(board);
	printMatrix<char>(board);
	boarderDFS(board);
	printMatrix<char>(board);
	replaceBoard(board);
	printMatrix<char>(board);


	return 0;
}
