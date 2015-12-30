/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

分析：遍历board找到和word首字母相同的位置，然后从该位置dfs看能否生成word。进行dfs时，对当前位置分别访问上下左右四个位置，
如果这些位置中的字母和word的下一个字母相同，则从这些位置继续搜索。对于board中元素已访问的标志可以设一个访问标志数组，
也可以把已访问的元素设置成某个字符，比如本文的代码就是设置成“#”，对该位置搜索完后要恢复原来的字母。
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
	row.push_back('A');
	row.push_back('B');
	row.push_back('C');
	row.push_back('E');
	matrix.push_back(row);

	row.clear();
	row.push_back('S');
	row.push_back('F');
	row.push_back('C');
	row.push_back('S');
	matrix.push_back(row);

	row.clear();
	row.push_back('A');
	row.push_back('D');
	row.push_back('E');
	row.push_back('E');
	matrix.push_back(row);
}

void initMask(int rows, int cols, vector< vector<bool> >& mask)
{
	vector<bool> row;
	for (int i = 0; i < cols; ++ i)
	{
		row.push_back(false);
	}

	for (int i = 0; i < rows; ++i)
	{
		mask.push_back(row);
	}

}

bool search(vector< vector<char> >& matrix, int row, int col, string& word, int index, vector< vector<bool> >& mask)
{
	if (index >= word.length())
		return true;

	int rows = matrix.size();
	int cols = matrix[0].size();

	if (row < rows - 1 && !mask[row + 1][col] && matrix[row + 1][col] == word.at(index))	// Down
	{
		mask[row + 1][col] = true;
		if (search(matrix, row + 1, col, word, index + 1, mask))
		{
			return true;
		}
		mask[row + 1][col] = false;
	}
	if (col < cols - 1 && !mask[row][col + 1] && matrix[row][col + 1] == word.at(index))	// Right
	{
		mask[row][col + 1] = true;
		if (search(matrix, row, col + 1, word, index + 1, mask))
		{
			return true;
		}
		mask[row][col + 1] = false;
	}
	if (row > 0 && !mask[row - 1][col] && matrix[row - 1][col] == word.at(index))			// Up
	{
		mask[row - 1][col] = true;
		if (search(matrix, row - 1, col, word, index + 1, mask))
		{
			return true;
		}
		mask[row - 1][col] = false;
	}
	if (col > 0 && !mask[row][col - 1] && matrix[row][col - 1] == word.at(index))			// Left
	{
		mask[row][col - 1] = true;
		if (search(matrix, row, col - 1, word, index + 1, mask))
		{
			return true;
		}
		mask[row][col - 1] = false;
	}

	return false;	// Reach here when non of the four corner matches
}

bool wordSearch(vector< vector<char> >& matrix, string& word)
{
	if (word.empty())
	{
		return true;
	}

	if (matrix.size() <= 0)
	{
		return false;
	}

	int rows = matrix.size();
	int cols = matrix[0].size();

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (matrix[i][j] == word.at(0))
			{
				vector< vector<bool> > mask;
				initMask(rows, cols, mask);
				mask[i][j] = true;
				if (search(matrix, i, j, word, 1, mask))
					return true;
				mask[i][j] = false;
			}
		}
	}

	return false;
}

int main(int argc, char ** argv)
{
	vector< vector<char> > board;

	populateBoard(board);
	printMatrix(board);

	string word("ABCCED");
	cout << "Search " << word << ", result is " << wordSearch(board, word) << endl;

	return 0;
}
