/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

/*
g++ -std=c++11 -o longestConsecutiveSequence longestConsecutiveSequence.cpp
*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestConsecutiveSequence(const vector<int>& input)
{
	if (input.empty())
	{
		return 0;
	}

	unordered_map<int, int> hTable;
	for(int i = 0; i < input.size(); ++ i)
	{
		hTable[input[i]] = i;					// Value -> index
	}

	int maxLen(1);

	for (int i = 0; i < input.size(); ++i)
	{
		int current = input[i];
		int currentLen(1);
		for (int k = current + 1; hTable.find(k) != hTable.end(); ++k )	// Search right
		{
			hTable.erase(k);
			++ currentLen;
		}

		for (int k = current - 1; hTable.find(k) != hTable.end(); --k )	// Search left
		{
			hTable.erase(k);
			++ currentLen;
		}

		if (currentLen > maxLen)
		{
			maxLen = currentLen;
		}

		if (hTable.empty())
		{
			break;
		}
	}

	return maxLen;
}

int main(int argc, char ** argv)
{
	vector<int> input;

	input.push_back(100);
	input.push_back(4);
	input.push_back(200);
	input.push_back(1);
	input.push_back(3);
	input.push_back(2);

	cout << longestConsecutiveSequence(input) << endl;

	return 0;
}
