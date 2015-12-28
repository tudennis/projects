/*
 * Take a look the following continuous permutation, can you find the patern?
 *
 *    1 2 3 4
 *    1 2 4 3
 *    1 3 2 4
 *    1 3 4 2
 *    1 4 2 3
 *    1 4 3 2
 *    2 1 3 4
 *    ...
 *
 * The pattern as below:
 *
 *    1) find the first place which num[i-1] < num[i]
 *    2) find the first number from n-1 to i which >= num[i-1]
 *    3) swap the 2) num with num[i-1]
 *    4) sort the sub-array [i, n) //actuall sort is fine as well
 *
 * For example:
 *
 *     1 4 3 2   <-- 1) find the first place which num[i-1] < num[i]
 *     ^
 *
 *     1 4 3 2   <-- 2) find the first number from n-1 to i which >= num[i-1]
 *     ^     ^
 *
 *     2 4 3 1   <-- 3) swap them
 *     ^     ^
 *
 *     2 4 3 1   <-- 4) sort
 *       ^   ^
 *
 *     2 1 3 4
 *
 * Edge Case:
 *
 *     4 3 2 1, the next permutation is 1 2 3 4
 */



#include <vector>
#include <algorithm>
#include <iostream>

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

	// 1. From backwards, find the first upwards trend nums[i-1] < nums[i]
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
	std::cout << "i: " << i << ", j: " << j << std::endl;
	std::swap(nums[i-1], nums[j]);

	std::for_each(nums.begin(), nums.end(), print);
	std::cout << std::endl;

	// 4. Sort [i, n)
	std::sort(nums.begin() + i, nums.end());
}

int main(int argc, char ** argv)
{
	std::vector<int> number;
	number.push_back(1);
	number.push_back(2);
	number.push_back(3);
	number.push_back(4);

	std::for_each(number.begin(), number.end(), print);
	std::cout << std::endl;

	nextPermutation(number);

	std::for_each(number.begin(), number.end(), print);
	std::cout << std::endl;

	return 0;
}



