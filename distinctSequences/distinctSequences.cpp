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

#include <iostream>

using namespace std;

int distinctSequences(string& s, string& t)
{
	return 0;
}

int main(int argc, char ** argv)
{
	string s("rabbbit");
	string t("rabbit");

	cout << "S: " << s << ", T: " << t << endl;

	cout << "The number of distinct sequences is: " << distinctSequences(s, t) << endl;

	return 0;
}
