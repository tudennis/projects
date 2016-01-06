/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string
by deleting some (can be none) of the characters without disturbing the relative
positions of the remaining characters.
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

#include <vector>
#include <algorithm>
#include <iostream>
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

template <typename T>
void printMatrix(const vector< vector<T> >& matrix)
{
	for_each(matrix.begin(), matrix.end(), printRow<T>);
	cout << endl;
}

/*
=====================
 Dynamic Programming
=====================

  The idea as below:

     Considering m[i][j] means the distance from T[i] to S[j], and add the empty "" case, then,

     A) Initialization for empty case:  m[0][j] = 1;

     B) Calculation

        a) Target-len > Source-len cannot found any substring
           i > j : m[i][j] = 0;

        b) if not equal, take the value of T[i] => S[j-1] (e.g. ["ra" => "rabb"] =["ra" => "rab"] )
           S[j] != T[i] :  m[i][j] = m[i][j-1]

        c) if equal. (e.g.  ["rab" => "rabb"] = ["rab" =>"rab"] + ["ra" => "rab"] )
           S[j] == T[i] :  m[i][j] = m[i][j-1] + m[i-1][j-1]

  1) Initialize a table as below
       ""  r  a  b  b  b  i  t
    ""  1  1  1  1  1  1  1  1
    r
    b
    t

  2) Calculation
       ""  r  a  b  b  b  i  t
    ""  1  1  1  1  1  1  1  1
    r   0  1  1  1  1  1  1  1
    b   0  0  0  1  2  3  3  3
    t   0  0  0  0  0  0  0  3
*/


int distinctSequences(string& s, string& t)
{
	int lenS(s.size()), lenT(t.size());

	vector< vector<int> > matrix(lenT + 1, vector<int>(lenS + 1, 0));

	printMatrix(matrix);

	for (int i = 0; i <= lenT; ++i)
	{
		for (int j = 0; j <= lenS; ++j)
		{
			if (i == 0)
			{
				matrix[i][j] = 1;
				continue;
			}

			if (i > j)
			{
				matrix[i][j] = 0;
				continue;
			}

			if (s[j - 1] == t[i - 1])
			{
				matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j - 1];
			}
			else
			{
				matrix[i][j] = matrix[i][j - 1];
			}
		}
	}

	printMatrix(matrix);

	return matrix[lenT][lenS];
}

int main(int argc, char ** argv)
{
	string s("rabbbit");
	string t("rabbit");

	cout << "S: " << s << ", T: " << t << endl;

	cout << "The number of distinct sequences is: " << distinctSequences(s, t) << endl;

	return 0;
}
