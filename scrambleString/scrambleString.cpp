/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 *  Definition
 *
 *      dp[k][i][j] means:
 *
 *         a) s1[i] start from 'i'
 *         b) s2[j] start from 'j'
 *         c) 'k' is the length of substring
 *
 *  Initialization
 *
 *      dp[1][i][j] = (s1[i] == s2[j] ? true : false)
 *
 *  Formula
 *
 *      same as the above recursive method idea
 *
 *      dp[k][i][j] =
 *          dp[divk][i][j] && dp[k-divk][i+divk][j+divk] ||
 *          dp[divk][i][j+k-divk] && dp[k-divk][i+divk][j]
 *
 *      `divk` mean split the k to two parts, so 0 <= divk <= k;
*/
bool isScrambleStringDP(const string& s1, const string& s2)
{
	if (s1.size() != s2.size())
	{
		return false;
	}

	if (s1 == s2)
	{
		return true;
	}

	string ss1(s1);
	string ss2(s2);

	sort(ss1.begin(), ss1.end());
	sort(ss2.begin(), ss2.end());

	if (ss1 != ss2)
	{
		return false;
	}

	int len = s1.size();

	vector< vector< vector< bool > > > dp(len + 1, vector< vector< bool > >(len, vector<bool>(len, false)));

	// init DP
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			dp[1][i][j] = (s1[i] == s2[j] ? true : false);
		}
	}

	for (int k = 2; k <= len; ++ k)
	{
		for (int i = 0; i < len - k + 1; ++i)
		{
			for (int j = 0; j < len - k + 1; ++j)
			{
				dp[k][i][j] = false;
				for (int divk = 1; divk < k && dp[k][i][j] == false; ++ divk)
				{
					dp[k][i][j] = ( dp[divk][i][j] && dp[k-divk][i+divk][j+divk] ) ||
							  	  ( dp[divk][i][j+k-divk] && dp[k-divk][i+divk][j] );
				}
			}
		}
	}

	return dp[len][0][0];
}

bool isScrambleStringRecursive(const string& s1, const string &s2)
{
	// cout << "s1: " << s1 << ", s2: " << s2 << endl;
	if (s1.size() != s2.size())
	{
		return false;
	}

	if (s1 == s2)
	{
		return true;
	}

	string ss1(s1);
	string ss2(s2);

	sort(ss1.begin(), ss1.end());
	sort(ss2.begin(), ss2.end());

	if (ss1 != ss2)
	{
		return false;
	}

	int len = s1.size();

	for (int i = 1; i < len; ++i)
	{
		if (isScrambleStringRecursive(s1.substr(0, i), s2.substr(0, i)) && isScrambleStringRecursive(s1.substr(i, len - i), s2.substr(i, len - i)))
			return true;

		if (isScrambleStringRecursive(s1.substr(0, i), s2.substr(len - i, i)) && isScrambleStringRecursive(s1.substr(i, len - i), s2.substr(0, len - i)))
			return true;

	}

	return false;
}

int main(int argc, char ** argv)
{
	string s1("great");
	string s2("rgtae");
	string s3("getra");

	cout << s1 << " : " << s2 << isScrambleStringRecursive(s1, s2) << endl;

	cout << s1 << " : " << s3 << isScrambleStringRecursive(s1, s3) << endl;

	cout << s1 << " : " << s2 << isScrambleStringDP(s1, s2) << endl;

	cout << s1 << " : " << s3 << isScrambleStringDP(s1, s3) << endl;

	return 0;
}
