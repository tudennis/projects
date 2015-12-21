/*
 * Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a")  false
isMatch("aa","aa")  true
isMatch("aaa","aa")  false
isMatch("aa", "*")  true
isMatch("aa", "a*")  true
isMatch("ab", "?*")  true
isMatch("aab", "c*a*b")  false
 */

#include <iostream>

bool match(const std::string& s, const std::string& pattern)
{
	if (s.size() == 0)
		return false;

	bool isMatch(true);

	size_t len_s = s.size();
	size_t len_pattern = pattern.size();

	int i(0), j(0);
	for (; i < len_s && j < len_pattern; ++i)
	{
		if (pattern[j] == '?')
		{
			++j;
		}
		else if (pattern[j] == '*')
		{

		}
		else if (s[i] == pattern[j])
		{
			++j;
		}
		else
		{
			isMatch = false;
			break;
		}
	}

	// s still has remaining characters
	if (i != len_s)
	{
		isMatch = false;
	}

	return isMatch;
}

int main(int argc, char** argv)
{
	std::string pattern("c*a*b");
	std::string s;

	std::cout << "String [" << s << "], pattern: [" << pattern << "]. "
			<< match(s, pattern) << std::endl;

	return 0;
}
