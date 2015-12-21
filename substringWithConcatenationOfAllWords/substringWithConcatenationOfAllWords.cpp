/*
You are given a string, s, and a list of words, words, that are all of the same length.
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

#include <vector>
#include <map>
#include <string>
#include <algorithm>	// std::for_each
#include <iostream>		// std::cout

void print1(int i)
{
	std::cout << " " << i;
}

void print2(std::pair<std::string, int> pair)
{
	std::cout << pair.first << ":" << pair.second << std::endl;
}

std::vector<int> findSubstring(const std::string& s, const std::vector<std::string>& words)
{
	std::vector<int> results;
	if (s.size() == 0 || words.size() == 0)
	{
		return results;
	}

	size_t n = s.size();
	size_t m = words.size();
	size_t l = words[0].size();

	// Create a count map
	std::map<std::string, int> expected;
	for (int i = 0; i < m; ++i)
	{
		if (expected.find(words[i]) == expected.end())
		{
			expected[words[i]] = 1;
		}
		else
		{
			++ expected[words[i]];
		}
	}

	std::for_each(expected.begin(), expected.end(), print2);

	for (int i = 0; i < l; ++i)
	{
		std::map<std::string, int> actual;
		int startIndex = i;
		int count = 0;
		for (int j = i; j <= n - l; j+=l)
		{
			std::string tmp = s.substr(j, l);

			// If tmp doesn't exist in words, the substring is interrupted
			// needs to start over
			if (expected.find(tmp) == expected.end())
			{
				actual.clear();
				count = 0;
				startIndex = j + l;
				continue;
			}

			++ count;
			// Add the tmp to actual
			if (actual.find(tmp) == actual.end())
			{
				actual[tmp] = 1;
			}
			else
			{
				++actual[tmp];
			}

			// More actual than expected for tmp
			// Remove all sub-string showed before the first occurance of tmp
			if (actual[tmp] > expected[tmp])
			{
				std::string word;
				do {
					word = s.substr(startIndex, l);
					-- count;
					-- actual[word];
					startIndex += 1;
				} while (word != tmp);
			}

			if (count == m) // Find one result
			{
				results.push_back(startIndex);
				std::string word(s.substr(startIndex, l));
				-- actual[word];
				startIndex += l;
				-- count;
			}
		}
	}

	return results;
}

int main(int argc, char ** argv)
{
	std::string s("barbarfooteafoobar");

	std::vector<std::string> words;
	words.push_back("bar");
	words.push_back("foo");

	std::vector<int> results = findSubstring(s, words);

	std::for_each(results.begin(), results.end(), print1);

	std::cout << std::endl;

	return 0;
}
