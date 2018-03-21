/*
	NOTES:
	input: a date in form YYYYMMDD
	output: a string of the day of the week the date was
	from /r/dailyprogrammer Challenge #338 : https://www.reddit.com/r/dailyprogrammer/comments/79npf9/20171030_challenge_338_easy_what_day_was_it_again/
*/

#include <stdio.h>

static const char days[][8] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int main()
{
	int y, m, d;
	while(scanf("%d%d%d", &y, &m, &d) == 3)
	{
		if(m < 3)
		{
			y--;
			m += 12;
		}
		int c = y / 100;
		int z = y % 100;
		int dow = (d + 13 * (m + 1) / 5 + z + z / 4 + c / 4 + 5 * c) % 7;
		printf("%s\n", days[dow]);
	}
}
