/*
 Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation
 sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the word list

For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.

*/

/*
 * II *****************
 Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation
 sequence(s) from beginWord to endWord, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the word list

For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

Note:

    All words have the same length.
    All words contain only lowercase alphabetic characters.
*/

#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

template <typename T, typename S>
void printPair(const pair<T, S>& p)
{
	cout << p.first << ", " << p.second << endl;
}

template <typename T, typename S>
void printMap(const map<T, S>& m)
{
	for_each(m.begin(), m.end(), printPair<T, S>);
	cout << endl;
}

int wordLadder(const string& beginWord, const string& endWord, set<string>& wordList)
{
	wordList.insert(endWord);	// WordList doesn't contain the end word

	map<string, int> result;
	result[beginWord] = 1;

	queue<string> q;
	q.push(beginWord);

	while (!q.empty())
	{
		string s = q.front();
		q.pop();	// pop

		if (s == endWord)
		{
			break;
		}
		for (int i = 0; i < s.size(); i++)
		{
			string temp = s;

			for(char c = 'a'; c <= 'z'; c++)
			{
				temp[i] = c;
				if (wordList.count(temp) > 0 && result.count(temp) == 0)
				{
					result[temp] = result[s] + 1;
					q.push(temp);
				}
			}
		}
	}

	printMap(result);

	return ((result.count(endWord) != 0) ? result[endWord] : 0);
}

int main(int argc, char ** argv)
{
	string beginWord("hit"), endWord("cog");
	set<string> wordList;
	wordList.insert("hot");
	wordList.insert("dot");
	wordList.insert("dog");
	wordList.insert("lot");
	wordList.insert("log");

	int len = wordLadder(beginWord, endWord, wordList);

	cout << "The shortest path is : " << len << endl;

	return 0;
}
