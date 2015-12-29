/*
 The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(int i)
{
	std::cout << i << " ";
}

void nextPermutation(std::vector<int>& nums)
{
	size_t s = nums.size();

	if (s <= 1)
	{
		return;
	}

	// 1. From backwards, find the first   / \ (upwards trend nums[i-1] < nums[i])
	// 									i-1 i
	size_t i = s - 1;
	std::vector<int>::iterator start;
	for (; i > 0; --i)
	{
		if (nums[i-1] < nums[i])
		{
			break;
		}
	}

	// 2. From backwards, find the first number nums[j] >= nums[i-1]
	size_t j = s - 1;
	for (; j > i - 1; --j)
	{
		if (nums[j] >= nums[i-1])
		{
			break;
		}
	}

	// 3. Swap i-1 and j
	std::swap(nums[i-1], nums[j]);

	// 4. Sort [i, n)
	std::sort(nums.begin() + i, nums.end());
}

vector<int> kthPermutation(vector<int>& input, int kth)
{
	if (kth <= 1)
	{
		return input;
	}

	vector<int> result = kthPermutation(input, kth - 1);

	// Do the next permutation
	nextPermutation(result);

	return result;
}

vector<int> kthPermutationOptimum(vector<int>& input, int kth)
{
	vector<int> result;

	int size = input.size();
	int total = 1;
	for (int i = 0; i < size; ++ i)
	{
		total *= input[i];
	}

	if (total < kth)
	{
		// Error handling
		return result;
	}

	for (int i = 0; i < size; ++ i)
	{
		total /= (size - i);

		int index = (kth - 1) / total;		// Index starts from 0 but the permutation starts from 1.

		result.push_back(input[index]);
		input.erase(input.begin() + index); // !!!!

		kth -= total * index;				// Remove corresponding number portion
	}

	return result;
}

int main(int argc, char ** argv)
{
	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);

	int kth = 4;

	// vector<int> result = kthPermutation(input, kth);
	vector<int> result = kthPermutationOptimum(input, kth);

	for_each(result.begin(), result.end(), print);
	cout << endl;

	return 0;
}
