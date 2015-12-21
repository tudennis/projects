/*
Given a string containing just the characters '(' and ')',

find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()",

which has length = 4.

*/

#include <vector>
#include <iostream>
#include <string>

void longestValidParenthesis(const std::string& s)
{

	std::vector<char> stack;
	int count = 0;
	int max_len = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
		{
			stack.push_back('(');
		}
		else if (s[i] == ')')
		{
			if (stack.size() > 0)
			{
				stack.pop_back();
				++ count;

				if (count > max_len)
				{
					max_len = count;
				}
			}
			else
			{
				stack.clear();
				count = 0;
			}
		}
		else
		{
			// Throw
		}
	}

	std::cout << "Max: " << max_len << std::endl;
}

int main(int argc, char ** argv)
{
	std::string s(")(())())(()()()()()()");

	longestValidParenthesis(s);

	return 0;
}
