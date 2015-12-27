/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

#include <iostream>
#include <vector>
#include <algorithm>

void rotateImage(std::vector< std::vector<int> >& image)
{
	if (image.size() == 0)
		return;

	if (image.size() != image[0].size())
	{
		// Error handling, throw
		return;
	}

	int n = image.size();

	for (int i = 0; i < n/2; ++ i)		// Going from outer circle into inner circle
	{
		std::vector<int> backup = image[i];

		// First deal with the four corners;
		int tmp = image[i][i];
		image[i][i] = image[n-i-1][i];
		image[n-i-1][i] = image[n-i-1][n-i-1];
		image[n-i-1][n-i-1] = image[i][n-i-1];
		image[i][n-i-1] = tmp;

		// Copy left column image[i..n-i-1][i] -> top row image[i][i ... n-i-1]
		for (int j = i + 1; j < n - i - 1; ++j)
		{
			image[i][j] = image[n - i - 1 - j][i];
		}

		// Copy bottom row image[n-i-1][i..n-i-1] -> left column image[i..n-i-1][i]
		for (int j = i + 1; j < n - i - 1; ++j)
		{
			image[j][i] = image[n - i - 1][j];
		}

		// Copy right column image[i..n-i-1][n-i-1] -> bottom row image[n-i-1][i..n-i-1]
		for (int j = i + 1; j < n - i - 1; ++j)
		{
			image[n - i - 1][n - i - 1 - j] = image[j][n - i - 1];
		}

		// Copy backup top row image[i][i..n-i-1] -> right column image[i..n-i-1][n-i-1]
		for (int j = i + 1; j < n - i - 1; ++j)
		{
			image[j][n - i - 1] = backup[j];
		}
	}
}

void printCell(int cell)
{
	std::cout << cell << " ";
}

void printRow(const std::vector<int>& row)
{
	std::for_each(row.begin(), row.end(), printCell);
	std::cout << std::endl;
}

void printImage(const std::vector< std::vector<int> >& image)
{
	std::for_each(image.begin(), image.end(), printRow);
	std::cout << std::endl;
}


int main(int argc, char **argv)
{
	std::vector< std::vector<int> > images;
	std::vector<int> row;
	row.push_back(1);
	row.push_back(2);
	row.push_back(3);
	row.push_back(3);
	images.push_back(row);

	row.clear();
	row.push_back(4);
	row.push_back(5);
	row.push_back(6);
	row.push_back(6);
	images.push_back(row);

	row.clear();
	row.push_back(7);
	row.push_back(8);
	row.push_back(9);
	row.push_back(9);
	images.push_back(row);

	row.clear();
	row.push_back(7);
	row.push_back(8);
	row.push_back(9);
	row.push_back(9);
	images.push_back(row);

	printImage(images);

	rotateImage(images);

	printImage(images);

	return 0;
}
