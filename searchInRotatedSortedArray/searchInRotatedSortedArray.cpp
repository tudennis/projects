/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index,

otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include <iostream>

#include <algorithm>

void print(int i)
{
	std::cout << i << " ";
}

int searchHelper(const int* array, int startIndex, int endIndex, int target)
{
	if (startIndex > endIndex)
	{
		return -1;
	}

	int mid = (startIndex + endIndex) / 2;

	if (array[mid] == target)
	{
		return mid;
	}
	else if (target < array[mid])
	{
		if (target >= array[startIndex])
			return searchHelper(array, startIndex, mid - 1, target);
		else
			return searchHelper(array, mid + 1, endIndex, target);
	}
	else
	{
		if (target <= array[endIndex])
			return searchHelper(array, mid + 1, endIndex, target);
		else
			return searchHelper(array, startIndex, mid - 1, target);
	}
}

int searchInRotatedSortedArray(const int* array, int size, int target)
{
	std::for_each(array, array+size, print);
	std::cout << std::endl;

	return searchHelper(array, 0, size - 1, target);
}


int main(int argsc, char** argv)
{
	int a[] = {4, 5, 6, 7, 8, 9, 10, 0, 1, 2};

	int target = 2;

	int index = searchInRotatedSortedArray(a, sizeof(a)/sizeof(int), target);

	std::cout << "Target index is:" << index << std::endl;

	return 0;
}
