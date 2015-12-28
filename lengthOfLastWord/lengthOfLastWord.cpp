/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/

#include <iostream>

using namespace std;

int lengthOfLastWord(string& input)
{
	int size = input.size();
	int i = size - 1;
	for (; i >= 0; --i)
	{
		if (input[i] == ' ')
		{
			break;
		}
	}

	return size - i - 1;
}

int main(int argc, char ** argv)
{
	string input("dfa fdsafdsafd");

	cout << "Input: " << input << endl;

	int len = lengthOfLastWord(input);

	cout << "The length of last word is: " << len << endl;

	return 0;
}
