/* NOTES:
	input: time in format HH::MM
	output: time in the format of a string of words
	from /r/dailyprogrammer Challege #321: https://www.reddit.com/r/dailyprogrammer/comments/6jr76h/20170627_challenge_321_easy_talking_clock/
*/

#include <stdio.h>
#include <string.h>

void interpret(char *parsed[])
{
	const char *half[] = {"am", "pm"};
	const char *digits[] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
	const char *teens[] = {"ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ",
						   "seventeen ", "eighteen ", "nineteen "};
	const char *tens[] = {"", "", "twenty ", "thirty ", "forty ", "fifty "};
	
	char *ret[32];
	int hour, min, i, evening;
	hour = atoi(parsed[0]);
	min = atoi(parsed[1]);
	
	/* check for illegal arguments */
	
	if(min > 59 || min < 0)
	{
		printf("Illegal argument: Please keep minute values between 00 and 59\n");
		return;
	}
	
	if(hour < 0)
	{
		printf("Illegal argument: Please keep hour values positive\n");
		return;
	}
	
	/* normalize any hours outside of 1 day */
	if(hour > 23)
	{
		while(hour > 23)
		{
			hour -= 24;
		}
	}
	
	/* interpret the input */
	i = evening = 0;

	if(hour > 11)
	{
		hour = hour - 12;
		evening = 1;
	}

	/* HOURS */
	if(hour == 0)
	{
		ret[i++] = teens[2];
	}else if(hour > 9)
	{
		ret[i++] = teens[hour-10];
	}else
	{
		ret[i++] = digits[hour];
	}
	
	/* MINUTES */
	if(min >= 1 && min < 10)
	{
		ret[i++] = "oh ";
		ret[i++] = digits[min];
	}else if(min > 9 && min < 20)
	{
		ret[i++] = teens[min - 10];
	}else
	{
		ret[i++] = tens[(min / 10)];
		ret[i++] = digits[min % 10];
	}
	
	if(evening)
		ret[i++] = "pm";
	else
		ret[i++] = "am";
	
	ret[i] = "\0";
	
	printf("It's ");
	i = 0;
	while(ret[i])
	{
		printf("%s", ret[i]);
		i++;
	}
	printf("\n");
}

int main (int argc, char *argv[])
{	
	int i;
	char line[32], *token, *parsed[32];	
	while(1)
	{
		START:
		printf("Enter a time (HH:MM) or \"exit\" to quit:\t");
		if(!fgets(line, 32, stdin))
			break;
		if(strcmp(line, "exit\n") == 0)
			break;
		
		for(i = 0; i < strlen(line); i++)
		{
			if(line[i] == '\n')
				line[i] = '\0';
		}
		
		for(i = 0; i < strlen(line); i++)
		{
			if(line[i] < 48 || line[i] > 58)
			{
				printf("Illegal argument: Please enter a valid time\n");
				goto START;
			}
		}
		
		token = strtok(line, ":");
		i = 0;
		while(token)
		{
			parsed[i] = token;
			i++;
			token = strtok(NULL, ":");
		}
		
		interpret(parsed);
	}
	
	return 0;
}
