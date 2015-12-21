/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

other solution involves using iteration instead of recursion -> getNext
*/

#include <iostream>		// std::cout
#include <sstream>		// std::ostringstream
#include <string>

std::string countAndSay(int n)
{
	std::string result;

	if (n < 0)
	{
		result = "";
	}
	else if (n == 1)
	{
		result = "1";
	}
	else if (n == 2)
	{
		result = "11";
	}
	else
	{
		std::string previousresult = countAndSay(n-1);

		int size = previousresult.size();

		char tmp = previousresult[0];
		int count = 1;
		int nextLocation = 1;

		std::ostringstream oss;

		while (nextLocation < size)
		{
			if (tmp == previousresult[nextLocation])
			{
				++ count;
			}
			else
			{
				oss << count << tmp;
				tmp = previousresult[nextLocation];
				count = 1;
			}

			++ nextLocation;
		}

		oss << count << tmp;	// Last iteration

		result = oss.str();
	}

	return result;
}


int main(int argc, char ** argv)
{
	int n = 5;

	std::string result = countAndSay(n);

	std::cout << result << std::endl;

	return 0;
}
