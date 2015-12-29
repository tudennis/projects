/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/



#include <iostream>

using namespace std;

int sqrt(int num)
{
	if (num <= 0)
	{
		return 0;
	}

	//the sqrt is not greater than x/2+1
	int e = num / 2 + 1;
	int s = 0;
	// binary search
	while ( s <= e )
	{
		int mid = s + (e-s)/2;
		long long sq = (long long)mid*(long long)mid;
		if (sq == num ) return mid;
		if (sq < num)
		{
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
	}
	return e;
}

int main(int argc, char ** argv)
{
	int num;

	cout << "Please enter an integer: " << endl;
	cin >> num;

	cout << "sqrt is: " << sqrt(num) << endl;

	return 0;
}
