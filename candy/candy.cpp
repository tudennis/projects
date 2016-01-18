/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?
*/

/*
 *    The solution is O(2n) run-time complexity
 *
 *    For example:
 *
 *        ratings[] = { 5, 6, 7, 4, 1, 2, 3, 2, 1, 7 }
 *
 *    1) Go through the ratings from left to right.
 *
 *       Find the each increasing sub-array, giving the minimal candy
 *
 *        ratings[] = { 5, 6, 7,   4,   1, 2, 3,   2,   1, 7 }
 *                      ------>    ->   ------>    ->   --->
 *          candy[] = { 1, 2, 3,   1,   1, 2, 3,   1,   1, 2 }
 *
 *    2) Go through the ratings from right to left.
 *
 *             ratings[] = { 5,   6,   7, 4, 1,   2,   3, 2, 1,   7 }
 *                           <-   <-   <------    <-   <------    <-
 *          prev_candy[] = { 1,   2,   3, 1, 1,   2,   3, 1, 1,   2 }
 *                                        +1              +1
 *               candy[] = { 1,   2,   3, 2, 1,   2,   3, 2, 1,   2 }
 *
 *    3) total candy is 19
 *
 */

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(vector<T>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

void candy(int * rating, int count)
{
	vector<int> candy(count, 1);

	for (int i = 1; i < count; ++ i)
	{
		if (rating[i] > rating[i - 1])
		{
			candy[i] = candy[i - 1] + 1;
		}
	}

	printVector<int>(candy);

	for (int i = count - 1; i > 0; --i)
	{
		if ((rating[i - 1] > rating[i]) && (candy[i - 1] <= candy[i]))
		{
			candy[i - 1] = candy[i] + 1;
		}
	}

	printVector<int>(candy);
}

int main(int argc, char ** argv)
{
	int rating[] = {5, 6, 7, 4, 1, 2, 3, 2, 1, 7};

	candy(rating, sizeof(rating)/sizeof(int));

	return 0;
}
