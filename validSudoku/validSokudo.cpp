/*
 Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled,
where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable.
Only the filled cells need to be validated.

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

bool isValidSudoku(const std::vector< std::vector<char> >& sukodu)
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

	printMatrix<bool>(rowMask);
	printMatrix<bool>(colMask);
	printMatrix<bool>(squareMask);

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

	std::cout << "Result masks: " << std::endl;
	printMatrix<bool>(rowMask);
	printMatrix<bool>(colMask);
	printMatrix<bool>(squareMask);

	return true;
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

	bool valid = isValidSudoku(sudoku);

	std::cout << "valid: " << valid << std::endl;

	return 0;
}
