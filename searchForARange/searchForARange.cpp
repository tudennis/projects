/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

#include <algorithm>

#include <iostream>

std::pair<int, int> rangeSearchHelper(const int *array, int startIndex, int endIndex, int target)
{

	if (startIndex > endIndex)
	{
		return std::make_pair<int, int>(-1, -1);
	}

	int mid = (startIndex + endIndex) / 2;

	if (array[mid] == target) // Not done yet in case of duplicates
	{
		int left(mid), right(mid);
		if (array[mid + 1] == target)
		{
			// Needs to continue
			// Still binary search
		}


		if (array[mid - 1] == target)
		{
			// Needs to continue
		}

		return std::make_pair<int, int>(left, right);
	}
	else if (target < array[mid])
	{
		return rangeSearchHelper(array, startIndex, mid - 1, target);
	}
	else
	{
		return rangeSearchHelper(array, mid + 1, endIndex, target);
	}

	return std::make_pair<int, int>(-1, -1);
}

std::pair<int, int> rangeSearch(const int* array, int size, int target)
{
	return rangeSearchHelper(array, 0, size - 1, target);
}

int main(int argc, char ** argv)
{
	int a[] = {5, 7, 7, 8, 8, 10};

	int target = 8;

	std::pair<int, int> result = rangeSearch(a, sizeof(a)/sizeof(int), target);

	std::cout << "[" << result.first << ", " << result.second << "]" << std::endl;

	return 0;
}
