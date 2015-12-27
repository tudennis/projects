/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    For the return value, each inner list's elements must follow the lexicographic order.
    All inputs will be in lower-case.

*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::map< std::string, std::vector<std::string> > groupAnagrams(const std::vector< std::string >& inputs)
{
	std::vector<std::string>::const_iterator itr = inputs.begin();

	std::map< std::string, std::vector<std::string> > results;
	while (itr != inputs.end())
	{
		std::string tmp = *itr;
		std::sort(tmp.begin(), tmp.end());

		std::map< std::string, std::vector<std::string> >::iterator it = results.find(tmp);

		if (it != results.end())
		{
			(it->second).push_back(*itr);
		}
		else
		{
			std::vector<std::string> t;
			t.push_back(*itr);
			results.insert(std::make_pair(tmp, t));
		}
		++ itr;
	}

	return results;
}


int main(int argc, char ** argv)
{
	std::vector<std::string> input;
	input.push_back("eat");
	input.push_back("tea");
	input.push_back("tan");
	input.push_back("ate");
	input.push_back("nat");
	input.push_back("bat");

	std::map< std::string, std::vector<std::string> > results = groupAnagrams(input);

	std::map< std::string, std::vector<std::string> >::const_iterator itr = results.begin();

	while (itr != results.end())
	{
		std::vector<std::string>::const_iterator it = itr->second.begin();
		while (it != itr->second.end())
		{
			std::cout << *it << " ";

			++ it;
		}
		std::cout << std::endl;
		++ itr;
	}

	return 0;
}
