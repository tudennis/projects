/*
Given two numbers represented as strings, return multiplication of the numbers

as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

#include <iostream>
#include <sstream>
#include <algorithm>

std::string addition(const std::string& number1, const std::string& number2)
{
	std::cout << "Add " << number1 << ", " << number2 << std::endl;
	if (number1.size() == 0)
		return number2;

	if (number2.size() == 0)
		return number1;

	// n1.size() > n2.size()
	std::string n1 (number1.size() > number2.size() ? number1 : number2);
	std::string n2 (number1.size() <= number2.size() ? number1 : number2);

	size_t len1 = n1.size();
	size_t len2 = n2.size();

	std::string result;

	int carry = 0;

	for (int i = len1 - 1, j = len2 -1; i >= 0; --i, --j)
	{
		int tmp = n1.at(i) - '0' + carry;
		if (j >= 0)
		{
			tmp += n2.at(j) - '0';
		}

		carry = tmp / 10;

		result.insert(result.begin(), tmp%10 + '0');
	}

	if (carry > 0)
	{
		result.insert(result.begin(), carry + '0');
	}

	return result;
}

std::string multiply(const std::string& n1, const std::string& n2)
{
	std::string result;

	size_t len1 = n1.size();
	size_t len2 = n2.size();

	for (int i = len1 - 1; i >= 0; --i)
	{
		int carry = 0;
		std::string val;
		for (int j = len2 - 1; j >= 0; --j)
		{
			int v = (n1.at(i) - '0') * (n2.at(j) - '0') + carry;
			val.insert(val.begin(), v%10 + '0');
			carry = v / 10;
		}
		if (carry > 0)
		{
			val.insert(val.begin(), carry+'0');
		}
		for (int t = i; t < len1 - 1; ++t)
		{
			val.push_back('0');
		}
		result = addition(result, val);
	}

	return result;
}

int main(int argc, char **argv)
{
	std::string number1("281");
	std::string number2("52");

	std::string result = multiply(number1, number2);

	std::cout << "Result is : " << result << std::endl;

	return 0;
}
