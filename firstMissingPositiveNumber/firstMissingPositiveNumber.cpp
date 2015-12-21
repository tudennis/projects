/*
 * Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
 */

#include <iostream>

int firstMissingPositiveNumber(int* a, int size)
{
	for (int i = 0; i < size; ++ i)
	{
		while (a[i] > 0 &&  a[i] < size && a[i] != i)
		{
			std::swap(i, a[i]);
		}
	}

	for (int i = 0; i < size; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < size; ++i)
	{
		if (a[i] != i)
			return i;
	}

	return size;
}

int main(int argc, char ** argv)
{
	int a[] =  {3, 4, -1, 1};

	int result = firstMissingPositiveNumber(a, sizeof(a)/sizeof(int));

	std::cout << "First missing positive number is: " << result << std::endl;

	return 0;
}
