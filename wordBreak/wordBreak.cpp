/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a
space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/


/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence
where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

//---------------------
// Dynamic Programming
//---------------------
//
//  Define substring[i, j] is the sub string from i to j.
//
//       (substring[i,j] == word) :   result[i] = substring[i,j] + {result[j]}
//
//      So, it's better to evaluate it backword.
//
//  For example:
//
//    s = "catsanddog",
//    dict = ["cat", "cats", "and", "sand", "dog"].
//
//       0  c  "cat"  -- word[0,2] + {result[3]}  ==> "cat sand dog"
//             "cats" -- word[0,3] + {result[4]}  ==> "cats and dog"
//       1  a  ""
//       2  t  ""
//       3  s  "sand" --  word[3,6] + {result[7]} ==> "sand dog"
//       4  a  "and"  --  word[4,6] + {result[7]} ==> "and dog"
//       5  n  ""
//       6  d  ""
//       7  d  "dog"
//       8  o  ""
//       9  g  ""

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
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

bool wordBreak(const string& word, const set<string>& dict)
{
	vector<bool> r(word.size(), false);

	for (int i = 0; i < word.size(); ++i)
	{
		string w = word.substr(0, i + 1);
		if (dict.find(w) != dict.end())
		{
			r[i] = true;
			continue;
		}

		for (int j = 0; j < i; ++j)
		{
			if (r[j])
			{
				w = word.substr(j + 1, i - j);
				if (dict.find(w) != dict.end())
				{
					r[i] = true;
					break;
				}
			}
		}
	}

	// printRow<bool>(r);

	return r[r.size() - 1];
}

vector<string> wordBreakII(const string& s, const set<string>& dict)
{
	vector< vector<string> > result(s.size());

	for(int i = s.size() - 1; i >= 0; --i)
	{
		for(int j = i + 1; j <= s.size(); ++j)
		{
			string word = s.substr(i, j - i);
			if (dict.find(word) != dict.end())
			{
				if (j == s.size())
				{
					result[i].push_back(word);
				}
				else
				{
					for(int k = 0; k < result[j].size(); ++k)
					{
						result[i].push_back(word + " " + result[j][k]);
					}
				}
			}
		}
	}

	return result[0];
}

int main(int argc, char ** argv)
{
	string word("leetcode");
	set<string> dict;
	dict.insert("leet");
	dict.insert("code");

	cout << wordBreak(word, dict) << endl;

	string wordII("catsanddog");
	set<string> dictII;
	dictII.insert("cat");
	dictII.insert("cats");
	dictII.insert("and");
	dictII.insert("sand");
	dictII.insert("dog");

	vector<string> result = wordBreakII(wordII, dictII);
	printRow<string>(result);

	return 0;
}
