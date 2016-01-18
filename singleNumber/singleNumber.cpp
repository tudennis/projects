/*
Given an array of integers, every element appears twice except for one. Find that single one.
*/

/*
Given an array of integers, every element appears three times except for one. Find that single one.
*/

/*
*  This solution is clear & straightforward implementation.
*
*  We use an array of 32 length(e.g. count[32]) to count the the bits for all of numbers.
*
*  Because the same number appear 3 times, which means the sum of i-th bits for all numbers should be 3 times.
*
*  In other word, the sum of the i-th bits mod 3, it must be 0 or 1. 1 means that is the single number bit.
*
* This solution can be easy to extend to "every element appears k times except for one."
*
*/

#include <iostream>
using namespace std;

int singleNumberII(int A[], int n)
{
	int count[32] = {0};
	int result = 0;
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((A[j] >> i) & 1)
			{
				count[i]++;
			}
		}
		result |= ((count[i] % 3) << i);
	}
	return result;
}

int singleNumber(int * a, int count)
{
	int result(0);

	for (int i = 0; i < count; ++i)
	{
		result = result ^ a[i];
	}

	return result;
}

int main(int argc, char ** argv)
{
	int a[]= {1, 5, 3, 1, 3};
	cout << singleNumber(a, sizeof(a)/sizeof(int)) << endl;

	int b[] = {1, 5, 3, 1, 1, 3, 3};
	cout << singleNumberII(b, sizeof(b)/sizeof(int)) << endl;

	return 0;
}
