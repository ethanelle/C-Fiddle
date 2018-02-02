#include <iostream>

int *calc(int change, int coins[])
{
	int i, j;
	static int ret[100];
	i = j = 0;
	
	while(change > 0)
	{
		if(change >= coins[i])
		{
			change -= coins[i];
			ret[j++] = coins[i];
		}
		if(change == 0)
			break;
		i++;
	}
	
	return ret;
}

int main()
{
	int coins[] = {100, 20, 18, 12, 5, 5};
	int change, limit;
	int *result;
	change = 130;
	
	result = calc(change, coins);
	
	std::cout << change << " can be made with:\t";
	for(int i = 0; i < 10; i++)
	{
		if(*(result + i) == 0)
			break;
		std::cout << *(result + i) << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
