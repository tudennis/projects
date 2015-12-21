/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.

*/

#include <iostream>

int trappingRainWater(int *a, int size)
{
	int result = 0;

	if (size > 1)
	{

		int highest = a[0];
		int highestIndex = 0;

		// 1. Find the highest point
		for (int i = 1; i < size; ++i)
		{
			if (a[i] > highest)
			{
				highest = a[i];
				highestIndex = i;
			}
		}

		// 2. From [0, highestIndex] -> if a[i] > a[i+1] -> Water can be retained
		int previousHigh = a[0];
		for (int i = 1; i < highestIndex; ++i)
		{
			if (a[i] > previousHigh)
			{
				previousHigh = a[i];
			}
			result += (previousHigh - a[i]);
		}

		// 3. From [highestIndex, size] -> if a[i] < a[i-1] -> water can be retained
		previousHigh = a[size - 1];
		for (int i = size - 1; i > highestIndex; --i)
		{
			if (a[i] > previousHigh)
			{
				previousHigh = a[i];
			}
			result += (previousHigh - a[i]);
		}

	}
	return result;
}

int main(int argc, char** argv)
{
	int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};

	int result = trappingRainWater(a, sizeof(a)/sizeof(int));

	std::cout << "Result is: " << result << std::endl;

	return 0;
}
