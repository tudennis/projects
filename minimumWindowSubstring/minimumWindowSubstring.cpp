/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T
in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

/*
 * Using unordered_map require C++ 11
 * g++ -std=c++11 -o minimumWindowSubstring minimumWindowSubstring.cpp
 *
 */

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void printPair(const pair<char, int>& p)
{
	cout << p.first << " -> " << p.second << endl;
}

void printMap(const unordered_map<char, int>& cMap)
{
	for_each(cMap.begin(), cMap.end(), printPair);
	cout << endl;
}

void populateCounts(string& str, unordered_map<char, int>& cMap)
{
	int size = str.size();

	for (int i = 0; i < size; ++i)
	{
		if (cMap.find(str.at(i)) != cMap.end())
		{
			cMap.find(str.at(i))->second ++;
		}
		else
		{
			cMap[str.at(i)] = 1;
		}
	}

	printMap(cMap);
}

string minimumWindowSubstring(string& S, string& T)
{
	string w("");
	unordered_map<char, int> SMap;
	unordered_map<char, int> TMap;

	populateCounts(S, SMap);
	populateCounts(T, TMap);

	int start = 0;
	int end = S.size() - 1;

	while (true)
	{
		char c = S.at(start);
		if (SMap[c] > TMap[c])
		{
			--SMap[c];
			++start;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		char c = S.at(end);
		if (SMap[c] > TMap[c])
		{
			--SMap[c];
			--end;
		}
		else
		{
			break;
		}
	}

	w = S.substr(start, end - start + 1);

	return w;
}

int main(int argc, char ** argv)
{
	string S("ADOBECODEBANC");
	string T("ABC");

	cout << "S: [" << S << "], T: [" << T << "]" << endl;
	cout << "The minimum window substring is: [" << minimumWindowSubstring(S, T) << "]"<< endl;


	return 0;
}
