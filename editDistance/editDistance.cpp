/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.

(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

/*
 *  Dynamic Programming
 *
 *    Definitaion
 *
 *        m[i][j] is minimal distance from word1[0..i] to word2[0..j]
 *
 *    So,
 *
 *        1) if word1[i] == word2[j], then m[i][j] == m[i-1][j-1].
 *
 *        2) if word1[i] != word2[j], then we need to find which one below is minimal:
 *
 *             min( m[i-1][j-1], m[i-1][j],  m[i][j-1] )
 *
 *             and +1 - current char need be changed.
 *
 *        Let's take a look  m[1][2] :  "a" => "ab"
 *
 *               +---+  +---+
 *        ''=> a | 1 |  | 2 | '' => ab
 *               +---+  +---+
 *
 *               +---+  +---+
 *        a => a | 0 |  | 1 | a => ab
 *               +---+  +---+
 *
 *        To know the minimal distance `a => ab`, we can get it from one of the following cases:
 *
 *            1) delete the last char in word1,  minDistance( '' => ab ) + 1
 *            2) delete the last char in word2,  minDistance(  a => a ) + 1
 *            3) change the last char,           minDistance( '' => a ) + 1
 *
 *
 *    For Example:
 *
 *        word1="abb", word2="abccb"
 *
 *        1) Initialize the DP matrix as below:
 *
 *               "" a b c c b
 *            "" 0  1 2 3 4 5
 *            a  1
 *            b  2
 *            b  3
 *
 *        2) Dynamic Programming
 *
 *               "" a b c c b
 *            ""  0 1 2 3 4 5
 *            a   1 0 1 2 3 4
 *            b   2 1 0 1 2 3
 *            b   3 2 1 1 1 2
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

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

int threeMin(int n1, int n2, int n3)
{
	if (n1 <= n2 && n1 <= n3)
		return n1;
	else if (n2 <= n1 && n2 <= n3)
		return n2;
	else
		return n3;
}

int editDistance(string& word1, string& word2)
{
	int distance = 0;

	int len1 = word1.length();
	int len2 = word2.length();

	// Initial DP matrix
	vector< vector<int> > dp;
	vector<int> v;
	for (int i = 0; i <= len2; ++i)
	{
		v.push_back(0);
	}
	for (int i = 0; i <= len1; ++i)
	{
		dp.push_back(v);
	}

	for (int i  = 0; i <= len1; ++i)
	{
		dp[i][0] = i;
	}
	for (int i = 0; i <= len2; ++i)
	{
		dp[0][i] = i;
	}

	printMatrix(dp);

	for (int i = 1; i <= len1; ++ i)
	{
		for (int j = 1; j <= len2; ++ j)
		{
			if (word1[i-1] == word2[j-1]) //!!!!
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = threeMin(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1;
			}
		}
	}

	printMatrix(dp);

	return dp[len1][len2];
}

int main(int argc, char ** argv)
{
	string word1, word2;
	cout << "Please enter the first word: " << endl;
	cin >> word1;

	cout << "Please enter the second word: " << endl;
	cin >> word2;

	cout << "The edit distance is : " << editDistance(word1, word2) << endl;

	return 0;
}
