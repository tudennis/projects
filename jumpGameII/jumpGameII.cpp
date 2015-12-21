/*
Given an array of non-negative integers, you are initially positioned at

the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2.

(Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */

#include <iostream>

int jumpGameIIHelper(int *a, int size, int pos)
{
	// Already arrived
	if (pos == size - 1)
	{
		return 0;
	}

	int currentMinJump(size - pos - 1);
	for (int i = 1; i <= a[pos]; ++i)
	{
		if (pos + i <= size - 1)
		{
			int nextJump = jumpGameIIHelper(a, size, pos + i);
			if (nextJump < currentMinJump)
			{
				currentMinJump = nextJump;
			}
		}
	}

	return currentMinJump + 1;
}

int jumpGameII(int *a, int size)
{
	return jumpGameIIHelper(a, size, 0);
}

int main(int argc, char **argv)
{
	int a[] = {2,3,1,1,4};

	int result = jumpGameII(a, sizeof(a)/sizeof(int));

	std::cout << "Minimal steps: " << result << std::endl;

	return 0;
}
