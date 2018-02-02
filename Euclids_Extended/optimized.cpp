#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int backsub(int a, int b, int *x, int *y)
{
	if(a == 0)
	{
		*x = *y = 0;
		return b;
	}
	
	int x1, y1;
	int gcd = backsub(b%a, a, &x1, &y1);
	
	*x = y1 - (b/a) * x1;
	*y = x1;
	
	return gcd;
}

int main()
{
	int a, b, x, y, gcd;
	clock_t start;
	double duration;
	cout << "Enter values for 'm' and 'n' separated by *return*:" << endl;
	cin >> a;
	cin >> b;
	cout << endl;
	
	start = clock();
	
	gcd = backsub(a, b, &x, &y);
	cout << "gcd(" << a << ", " << b << ") = " << gcd << endl;
	cout << gcd << " = " << "(" << a << "*" << x << ") + (" << b << "*" << y << ")" << endl;
	
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	cout << duration << endl;
	
	return 0;
}
