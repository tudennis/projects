/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int total)
{
	if (total < 0)
	{
		// Error handing
	}

	vector<int> ways;
	ways.push_back(1);	// Total = 1
	ways.push_back(2);	// Total = 2


	for (int i = 2; i < total; ++i)
	{
		ways.push_back(ways[i-1] + ways[i-2]);
	}

	return ways[total - 1];
}

int main(int argc, char ** argv)
{
	int total;
	cout << "Enter an integer: " << endl;
	cin >> total;

	cout << "Distinct ways: " << climbStairs(total) << endl;

	return 0;
}
