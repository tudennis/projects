/*
Given a set of distinct integers, nums, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void printVal(const int val)
{
	cout << val << " ";
}

void printRow(const vector<int>& row)
{
	for_each(row.begin(), row.end(), printVal);
	cout << endl;
}

void printMatrix(const vector< vector<int> >& matrix)
{
	for_each(matrix.begin(), matrix.end(), printRow);
	cout << endl;
}

void getCombination(vector<int> &v, int n, int k, vector<int>& solution, vector< vector<int> >& result )
{
    if (k == 0)
    {
        //sort to meet LeetCode requirement
        vector<int> v = solution;
        sort(v.begin(), v.end());
        result.push_back(v);
        return;
    }

    for(int i = n; i > 0; i--)
    {
        solution.push_back(v[i-1]);
        getCombination(v, i-1, k-1, solution, result);
        solution.pop_back();
    }
}

vector<vector<int> > combine(vector<int> &v, int k)
{
    vector<vector<int> > result;
    vector<int> solution;
    getCombination(v, v.size(), k, solution, result);
    return result;
}

vector< vector<int> > subsets(vector<int>& input)
{
	vector<vector<int> > result;
	for(int i = 0; i <= input.size(); i++)
	{
		vector<vector<int> > r = combine(input, i); 	// Get all size i subset
		result.insert(result.end(), r.begin(), r.end());
	}
	return result;
}

int main(int argc, char ** argv)
{
	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);

	printRow(input);

	vector< vector<int> > results = subsets(input);

	printMatrix(results);

	return 0;
}
