/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */

#include <iostream>
#include <vector>
#include <algorithm>

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

template <typename T>
void printMatrix(const vector< vector<T> >& matrix)
{
	for_each(matrix.begin(), matrix.end(), printRow<T>);
	cout << endl;
}

void pascalTriangle(int num)
{
	vector< vector<int> > results;

	for (int i = 1; i <= num; ++i)
	{
		vector<int> r;
		if (i == 1)
		{
			r.push_back(i);
			results.push_back(r);
			continue;
		}

		vector<int>& previous = *(results.rbegin());
		int size = previous.size();
		for (int j = 0; j < size; ++j)
		{
			if (j == 0)
			{
				r.push_back(previous[j]);
			}
			else
			{
				r.push_back(previous[j - 1] + previous[j]);
			}
		}
		r.push_back(previous[size - 1]); // Last one

		results.push_back(r);
	}

	printMatrix(results);
}

int main(int argc, char ** argv)
{
	cout << "Please enter an integer: " << endl;
	int num;

	cin >> num;

	pascalTriangle(num);

	return 0;
}
