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

}

void printCell(int cell)
{
	std::cout << cell << " " << std::endl;
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
	images.push_back(row);

	row.clear();
	row.push_back(4);
	row.push_back(5);
	row.push_back(6);
	images.push_back(row);

	row.clear();
	row.push_back(7);
	row.push_back(8);
	row.push_back(9);
	images.push_back(row);

	printImage(images);

	rotateImage(images);


	return 0;
}
