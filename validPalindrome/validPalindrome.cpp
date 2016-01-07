/*
Given a string, determine if it is a palindrome, considering only alphanumeric
characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/


#include <iostream>
using namespace std;

bool validChar(char c)
{
	return (c >= 'A' && c <='Z') || (c >= 'a' && c <='z');
}

bool equalChar(char c1, char c2)
{
	return (tolower(c1) == tolower(c2));
}

bool validPalindrome(string& input)
{
	bool result(true);

	if (input.empty())
	{
		return result;
	}

	int s(0), e(input.size() - 1);

	while (s <= e)
	{
		while (s <= e && !validChar(input.at(s)))
		{
			++s;
		}

		while (e >= s && !validChar(input.at(e)))
		{
			--e;
		}

		if (!equalChar(input.at(s), input.at(e)))
		{
			result = false;
			break;
		}

		++ s;
		-- e;
	}

	return result;
}

int main(int argc, char ** argv)
{
	string input("A man, a plan, a canal: Panama");

	cout << "Is [" << input << "] valid palindrome? "
			<< (validPalindrome(input) ? "Yes" : "No") << endl;

	return 0;
}
