/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

/*
 The idea is as following:
 Starting from one element from the first position
 [1]
 Then insert the number from the second position to all the possible locations from the previous results
 [2, 1]
 [1, 2]
 Repeat the step till the number at the last position
 [3, 2, 1]
 [2, 3, 1]
 [2, 1, 3]
 [3, 1, 2]
 [1, 3, 2]
 [1, 2, 3]
 */

/*********************************With Duplication********************************/
void addNextWithDuplication(const std::vector<int>& v, int value, std::set< std::vector<int> >& results)
{
	int count = v.size();

	for (int pos = 0; pos < count + 1; ++pos)	// For each position in the previous permutation
	{
		std::vector<int> tmp = v;
		tmp.insert(tmp.begin() + pos, value);
		results.insert(tmp);
	}
}

void permutationWithDuplicate(int* a, int size, std::set< std::vector<int> >& results)
{
	if (size == 0)
		return;

	std::vector<int> tmp;
	tmp.push_back(a[0]);
	results.insert(tmp);

	std::set< std::vector<int> > newResults;

	for (int pos = 1; pos < size; ++pos)				// For every number
	{
		std::set< std::vector<int> > newResults;

		std::set< std::vector<int> >::const_iterator itr = results.begin();
		while (itr != results.end())
		{
			addNextWithDuplication(*itr, a[pos], newResults);
			++ itr;
		}

		results = newResults;
	}
}

/*********************************Without Duplication********************************/
void addNext(const std::vector<int>& v, int value, std::vector< std::vector<int> >& results)
{
	int count = v.size();

	for (int pos = 0; pos < count + 1; ++pos)	// For each position in the previous permutation
	{
		std::vector<int> tmp = v;
		tmp.insert(tmp.begin() + pos, value);
		results.push_back(tmp);
	}
}


void permutate(int* a, int size, std::vector< std::vector<int> >& results)
{
	if (size == 0)
		return;

	std::vector<int> tmp;
	tmp.push_back(a[0]);
	results.push_back(tmp);

	std::vector< std::vector<int> > newResults;

	for (int pos = 1; pos < size; ++pos)				// For every number
	{
		std::vector< std::vector<int> > newResults;

		int currentResultCount = results.size();
		for (int i = 0; i < currentResultCount; ++i)	// For every existing permutation prior add the number
		{
			addNext(results[i], a[pos], newResults);
		}

		results = newResults;
	}

}

void print2(int v)
{
	std::cout << v << " ";
}

void print1(const std::vector<int>& v)
{
	std::for_each(v.begin(), v.end(), print2);
	std::cout << std::endl;
}

int main(int argc, char ** argv)
{
	int a[] = {1, 2, 3, 3};

	// std::vector< std::vector<int> > results;
	// permutate(a, sizeof(a)/sizeof(int), results);

	std::set< std::vector<int> > results;
	permutationWithDuplicate(a, sizeof(a)/sizeof(int), results);

	std::for_each(results.begin(), results.end(), print1);

	return 0;
}
