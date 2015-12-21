/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

#include <iostream>
#include <vector>
#include <algorithm>

void permutate(int* a, int size, std::vector< std::vector<int> >& results)
{

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
	int a[] = {1, 2, 3};

	std::vector< std::vector<int> > results;

	permutate(a, sizeof(a)/sizeof(int), results);

	std::for_each(results.begin(), results.end(), print1);

	return 0;
}
