/*

Given a set of candidate numbers (C) and a target number (T),

find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
1. All numbers (including target) will be positive integers.
2. Elements in a combination (a1, a2, ... , ak) must be in non-descending order.
(ie, a1 <= a2 <= ... <= ak).
3. The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]

*/

#include <vector>
#include <iostream>
#include <algorithm>

void print2(int v)
{
	std::cout << v << " ";
}

void print1(std::vector<int>& v)
{
	std::for_each(v.begin(), v.end(), print2);
	std::cout << std::endl;
}

////////////////////////////////////////////////////////////////////////////
void combinationSumAllowDuplicatesHelper(const std::vector<int>& numbers, int target,
							int pos,
							std::vector<int>& result,
							std::vector< std::vector<int> >& results)
{
	if (target == 0)
	{
		results.push_back(result);
		return;
	}
	else if (target < 0)
	{
		return;
	}

	for (int i = pos; i < numbers.size(); ++i)
	{
		result.push_back(numbers[i]);
		combinationSumAllowDuplicatesHelper(numbers, target - numbers[i], i, result, results);
		result.pop_back();
	}
}


std::vector< std::vector<int> > combinationSumAllowDuplicates(const std::vector<int>& numbers, int target)
{
	std::vector< std::vector<int> > results;

	std::vector<int> result;

	combinationSumAllowDuplicatesHelper(numbers, target, 0, result, results);

	return results;
}
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
void combinationSumNoDuplicatesHelper(const std::vector<int>& numbers, int target,
							int pos,
							std::vector<int>& result,
							std::vector< std::vector<int> >& results)
{
	if (target == 0)
	{
		results.push_back(result);
		return;
	}
	else if (target < 0)
	{
		return;
	}

	for (int i = pos; i < numbers.size(); ++i)
	{
		result.push_back(numbers[i]);
		combinationSumNoDuplicatesHelper(numbers, target - numbers[i], i + 1, result, results);
		result.pop_back();
	}
}


std::vector< std::vector<int> > combinationSumNoDuplicates(const std::vector<int>& numbers, int target)
{
	std::vector< std::vector<int> > results;

	std::vector<int> result;

	combinationSumNoDuplicatesHelper(numbers, target, 0, result, results);

	return results;
}

////////////////////////////////////////////////////////////////////////////


int main(int argc, char ** argv)
{
	int a[] = {1, 2, 3, 4};

	std::vector<int> numbers(a, a + sizeof(a)/sizeof(int));
	int target = 7;

	///////////////Allow Duplicates//////////////////////
	std::vector< std::vector<int> > results = combinationSumAllowDuplicates(numbers, target);

	std::cout << "Allow Duplicates" << std::endl;
	std::for_each(results.begin(), results.end(), print1);

	//////////////No Duplicates//////////////////////////
	results.clear();
	results = combinationSumNoDuplicates(numbers, target);

	std::cout << "No Duplicates" << std::endl;
	std::for_each(results.begin(), results.end(), print1);

	return 0;
}
