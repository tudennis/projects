/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

*/

#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
void printElement(T value)
{
	std::cout << value << " ";
}

template <typename T>
void printRow(const std::vector<T>& row)
{
	std::for_each(row.begin(), row.end(), printElement<T>);
	std::cout << std::endl;
}

template <typename T>
void printMatrix(const std::vector< std::vector<T> >& sukodu)
{
	std::for_each(sukodu.begin(), sukodu.end(), printRow<T>);
	std::cout << std::endl;
}

bool isValid(const std::vector< std::vector<char> >& sukodu)
{
	// Initialize masks
	const int size = 9;
	std::vector< std::vector<bool> > rowMask, colMask, squareMask;
	std::vector<bool> initValue (size, false);
	for (int i = 0; i < size; ++ i)
	{
		rowMask.push_back(initValue);
		colMask.push_back(initValue);
		squareMask.push_back(initValue);
	}

	// printMatrix<bool>(rowMask);
	// printMatrix<bool>(colMask);
	// printMatrix<bool>(squareMask);

	for (int r = 0; r < size; ++ r)
	{
		for (int c = 0; c < size; ++ c)
		{
			if (sukodu[r][c] == '.')
				continue;

			int idx = sukodu[r][c] - '0' - 1;
			// 1. Check row mask
			if (rowMask[r][idx])
			{
				return false;
			}
			rowMask[r][idx] = true;

			// 2. Check col mask
			if (colMask[c][idx])
			{
				return false;
			}
			colMask[c][idx] = true;

			// 3. Check square mask
			int square = (r/3) * 3 + c/3;
			if (squareMask[square][idx])
			{
				return false;
			}
			squareMask[square][idx] = true;
		}
	}

	// std::cout << "Result masks: " << std::endl;
	// printMatrix<bool>(rowMask);
	// printMatrix<bool>(colMask);
	// printMatrix<bool>(squareMask);

	return true;
}


// An optimization can be make rowMask/colMask/squareMask static local to file
// and then instead of calling isValid everytime, just check the masks
// but the outside loop still the same
bool solve(std::vector< std::vector<char> >& sudoku)
{
	const int size = 9;
	// Recursively solve
	// 1. Find next unsolved spot
	bool hasUnsolved(false);
	int r(0), c(0);
	for (r = 0; r < size; ++r)
	{
		for (c = 0; c < size; ++c)
		{
			if (sudoku[r][c] == '.')
			{
				hasUnsolved = true;
				break;
			}
		}

		if (hasUnsolved)
		{
			break;
		}
	}

	if (!hasUnsolved)
	{
		return true;
	}

	// 2. Try 1 - 9
	bool solved = false;
	for (int v = '1'; v <= '9'; ++v)
	{
		sudoku[r][c] = v;
		if (isValid(sudoku) && solve(sudoku))
		{
			solved = true;
			break;
		}
		else
		{
			sudoku[r][c] = '.';
		}
	}

	return solved;
}

void populateSudoku(std::vector< std::vector<char> >& sukodu)
{
	std::vector<char> tempRow;

	tempRow.clear();
	tempRow.push_back('5');tempRow.push_back('3');tempRow.push_back('.');
	tempRow.push_back('.');tempRow.push_back('7');tempRow.push_back('.');
	tempRow.push_back('.');tempRow.push_back('.');tempRow.push_back('.');
	sukodu.push_back(tempRow);

	tempRow.clear();
	tempRow.push_back('6');tempRow.push_back('.');tempRow.push_back('.');
	tempRow.push_back('1');tempRow.push_back('9');tempRow.push_back('5');
	tempRow.push_back('.');tempRow.push_back('.');tempRow.push_back('.');
	sukodu.push_back(tempRow);

	tempRow.clear();
	tempRow.push_back('.');tempRow.push_back('9');tempRow.push_back('8');
	tempRow.push_back('.');tempRow.push_back('.');tempRow.push_back('.');
	tempRow.push_back('.');tempRow.push_back('6');tempRow.push_back('.');
	sukodu.push_back(tempRow);

	tempRow.clear();
	tempRow.push_back('8');tempRow.push_back('.');tempRow.push_back('.');
	tempRow.push_back('.');tempRow.push_back('6');tempRow.push_back('.');
	tempRow.push_back('.');tempRow.push_back('.');tempRow.push_back('3');
	sukodu.push_back(tempRow);

	tempRow.clear();
	tempRow.push_back('4');tempRow.push_back('.');tempRow.push_back('.');
	tempRow.push_back('8');tempRow.push_back('.');tempRow.push_back('3');
	tempRow.push_back('.');tempRow.push_back('.');tempRow.push_back('1');
	sukodu.push_back(tempRow);

	tempRow.clear();
	tempRow.push_back('7');tempRow.push_back('.');tempRow.push_back('.');
	tempRow.push_back('.');tempRow.push_back('2');tempRow.push_back('.');
	tempRow.push_back('.');tempRow.push_back('.');tempRow.push_back('6');
	sukodu.push_back(tempRow);

	tempRow.clear();
	tempRow.push_back('.');tempRow.push_back('6');tempRow.push_back('.');
	tempRow.push_back('.');tempRow.push_back('.');tempRow.push_back('.');
	tempRow.push_back('2');tempRow.push_back('8');tempRow.push_back('.');
	sukodu.push_back(tempRow);

	tempRow.clear();
	tempRow.push_back('.');tempRow.push_back('.');tempRow.push_back('.');
	tempRow.push_back('4');tempRow.push_back('1');tempRow.push_back('9');
	tempRow.push_back('.');tempRow.push_back('.');tempRow.push_back('5');
	sukodu.push_back(tempRow);

	tempRow.clear();
	tempRow.push_back('.');tempRow.push_back('.');tempRow.push_back('.');
	tempRow.push_back('.');tempRow.push_back('8');tempRow.push_back('.');
	tempRow.push_back('.');tempRow.push_back('7');tempRow.push_back('9');
	sukodu.push_back(tempRow);
}

int main(int argc, char ** argv)
{
	std::vector< std::vector<char> > sudoku;

	populateSudoku(sudoku);

	printMatrix<char>(sudoku);

	if(! isValid(sudoku))
	{
		std::cout << "Invalid sudoku" << std::endl;
		return 0;
	}

	solve(sudoku);

	std::cout << "Solved sudoku: " << std::endl;
	printMatrix<char>(sudoku);
	return 0;
}
