/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/


#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

template <typename T>
void printVal(const T& val)
{
	cout << val << " ";
}

template <typename T>
void printRow(const vector<T>& row)
{
	for_each(row.begin(), row.end(), printVal<T>);
	cout << endl;
}

int prefixOne(int number, int n)
{
	int v = pow(2, n);

	return number | v;
}

void grayCode(int n, vector<int> & results)
{
	if (n <= 0)
	{
		// Error handling
		return;
	}

	if (n == 1)	// base case
	{
		results.push_back(0);
		results.push_back(1);
		return;
	}

	grayCode(n - 1, results);

	vector<int> temp = results;

	printRow<int>(temp);

	int len = results.size();

	for(int i = len - 1; i >= 0; --i)
	{
		results.push_back(prefixOne(temp[i], n - 1));
	}

}

int main(int argc, char **argv)
{
	int n;

	cout << "Please enter n: " << endl;
	cin >> n;

	vector<int> results;
	grayCode(n, results);

	printRow<int>(results);

	return 0;
}
