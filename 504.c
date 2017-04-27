/*
* Author: hulk
* Date: 2017-04-26 10:45:29
*/

/*Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"*/
char* convertToBase7(int num) {

  int x = num;
  if(num < 0) x = -num;
  char *base7 = (char*)malloc(0);
  int i = 0;
  if (x == 0)
	{
		base7 = (char*)realloc(base7, sizeof(char)*(i+1));
  		base7[i++] = '0';
  		return base7;
	}
  while(x)
  {
  	base7 = (char*)realloc(base7, sizeof(char)*(i+1));
  	base7[i++] = x%7 + '0';
  	x /= 7;
  }
  if(num < 0)
  {
  	 base7 = (char*)realloc(base7, sizeof(char)*(i+1));
  	 base7[i++] = '-';
  }
  int m,n;
  char c;
  for ( m = 0, n = i-1; m < n; m++, n--)
  {
  	c = base7[m];
  	base7[m] = base7[n];
  	base7[n] = c;
  }
  return base7;
}