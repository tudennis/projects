/*
Implement pow(x, n)
*/

#include <iostream>

double pow(double x, int n)
{
	bool negativeExp = (n < 0 );
	double result = 1;

	int power = n;
	if (negativeExp)
	{
		power = (-n);
	}

	while (power > 0)
	{
		result *= x;
		--power;
	}

	if (negativeExp)
	{
		result = (1/result);
	}

	return result;
}

/*
 *   Basically, most people think this is very easy as below:
 *
 *      double result = 1.0;
 *      for (int i=0; i<n; i++){
 *           result *=x;
 *      }
 *
 *   However,
 *
 *     1) We need think about the `n` is negtive number.
 *
 *     2) We need more wisely deal with the following cases:
 *
 *         pow(1, MAX_INT);
 *         pow(-1,BIG_INT);
 *         pow(2, BIG_INT);
 *
 *        To deal with such kind case, we can use x = x*x to reduce the `n` more quickly
 *
 *        so, if `n` is an even number, we can `x = x*x`, and `n = n>>1;`
 *            if `n` is an odd number, we can just `result *= x;`
 *
 */

double pow2(double x, int n)
{
    bool sign = false;
    unsigned int exp = n;
    if(n<0){
        exp = -n;
        sign = true;
    }
    double result = 1.0;
    while (exp) {
        if (exp & 1){
            result *= x;
        }
        exp >>= 1;
        x *= x;
    }

    return sign ? 1/result : result;

}

int main(int argc, char ** argv)
{
	double input;
	int power;

	std::cout << "Please input a number and return: ";
	std::cin >> input;

	std::cout << "Please input the power and return: ";
	std::cin >> power;

	std::cout << "The number is :" << input << ", and the power is : " << power << std::endl;

	double result = pow(input, power);

	std::cout << "The result is : " << result << std::endl;

	return 0;
}
