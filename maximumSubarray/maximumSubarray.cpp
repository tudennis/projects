/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

#include <iostream>
using namespace std;

int maximumSubarray(int *a, int n, int& startIndex, int& endIndex)
{
	if (n == 0)
	{
		return 0;
	}

	int globalMax(a[0]), localMax(a[0]), localStart(0), localEnd(0);


	for (int i = 1; i < n; ++i)
	{
		localMax += a[i];
		if (localMax < 0)
		{
			localMax = 0;
			localStart = localEnd = i + 1;
		}
		else
		{
			localEnd = i;
			if (localMax > globalMax)
			{
				startIndex = localStart;
				endIndex = localEnd;
				globalMax = localMax;
			}
		}
	}

	return globalMax;
}


int main(int argc, char ** argv)
{
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};

	int startIndex(0), endIndex(0);

	int maxSum = maximumSubarray(a, sizeof(a)/sizeof(int), startIndex, endIndex);

	cout << "Maximum subarray sum is: " << maxSum << endl;

	for (int i = startIndex; i <= endIndex; ++i)
	{
		cout << a[i] << ", " ;
	}

	cout << endl;

	return 0;
}
