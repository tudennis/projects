/*
Given a sorted array and a target value, return the index if the target is found.

If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 -> 2
[1,3,5,6], 2 -> 1
[1,3,5,6], 7 -> 4
[1,3,5,6], 0 -> 0

*/

#include <algorithm>		// size_t
#include <iostream>

bool searchInsertPositionHelper(const int* array, int startIndex, int endIndex, int target, int& targetIndex)
{
	bool found(false);

	if (startIndex > endIndex)
	{
		return found;
	}

	// int mid = (startIndex + endIndex) / 2; // <- might cause overflow, use below
	int mid = startIndex + (endIndex - startIndex) / 2;

	// std::cout << "startIndex: " << startIndex << ", endIndex: " << endIndex << std::endl;

	if (array[mid] == target)
	{
		found = true;
		targetIndex = mid;
	}
	else if (target < array[mid])
	{
		if (mid == startIndex || target > array[mid - 1])
		{
			targetIndex = mid;
		}
		else
		{
			found = searchInsertPositionHelper(array, startIndex, mid - 1, target, targetIndex);
		}
	}
	else // target > array[mid]
	{
		if (mid == endIndex || target < array[mid + 1])
		{
			targetIndex = mid + 1;
		}
		else
		{
			found = searchInsertPositionHelper(array, mid + 1, endIndex, target, targetIndex);
		}
	}

	return found;
}

bool searchInsertPosition(const int* array, int size, int target, int& targetIndex)
{
	bool found(false);

	found = searchInsertPositionHelper(array, 0, size - 1, target, targetIndex);

	return found;
}


int main(int argc, char** argv)
{
	int targetIndex(0);

	int a[] = {1, 3, 5, 6};
	int target = 0;

	bool found = searchInsertPosition(a, sizeof(a)/sizeof(int), target, targetIndex);

	std::cout << "Found: " << found << ", target: " << target << ", targetIndex: " << targetIndex << std::endl;

	return 0;
}
