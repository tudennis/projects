/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

#include <iostream>
#include <vector>
using namespace std;

int uniqueBST(int n)
{
	vector<int> count(n + 1, 0);
	count[0] = 1;		// c[0] = 1

	for (int i = 1; i <= n; ++ i)
	{
		for (int j = 0; j < i; ++j)
		{
			count[i] += (count[j] * count[i - 1 - j]);
		}
	}

	return count[n];
}

int main(int argc, char ** argv)
{
	int n;
	cout << "Enter number: " << endl;
	cin >> n;

	cout << "Unique binary search trees for " << n  << " nodes is " << uniqueBST(n) << endl;

	return 0;
}
