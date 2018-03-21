/*
	NOTES:
	Input: number from the command line
	Output: smallest integer that is made from the addition of two of the input's factors
	from /r/dailyprogrammer Challenge #354: https://www.reddit.com/r/dailyprogrammer/comments/83uvey/20180312_challenge_354_easy_integer_complexity_1/
*/

#include <iostream>
#include <string>

void complexity(long val)
{
	long sum = val + 1;
	for(long i = 1; i < val; i++)
	{
		if(val % i == 0)
		{
			long temp = (val / i) + i;
			if(temp < sum)
				sum = temp;
		}
	}
	std::cout << sum << std::endl;
}

int main(int argc, const char* argv[])
{
	std::cout << "Enter a number: ";
	long line;
	std::cin >> line;
	complexity(line);
	return 0;
}
