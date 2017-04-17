/*
* Author: hulk
* Date: 2017-04-12 20:29:38
*/

/*
pow(x,n)
*/
#include <stdio.h>

double myPow(double x, int n)
{
	if (!n)
	{
		return 1.0;
	}
	if (n < 0)
	{
		n = -n;
		x = 1/x;
	}

	return (n%2==0)?myPow(x*x,n/2):x*myPow(x*x,n/2);
}

int main(int argc, char const *argv[])
{
	double x;
	int i;
	scanf("%lf %d", &x, &i);
	printf("%lf\n", myPow(x,i));
	return 0;
}
