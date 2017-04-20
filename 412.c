/*
* Author: hulk
* Date: 2017-04-18 17:01:44
*/
/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number 
and for the multiples of five output “Buzz”. 
For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]*/

int getDigit(int x)
{
	int i = 0;
	while(x)
	{
		i++;
		x /= 10;
	}
	return i;
}

bool isMultipleOfN(int i, int n)
{
	if ((i/n)*n == i)
	{
		return true;
	}
	else return false;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char* fizz = "Fizz";
    char* buzz = "Buzz";
    char* fizzBuzz = "FizzBuzz";
    *returnSize = n;
    char** result = (char**)malloc(sizeof(char*)*n);

    int i;
    for (i = 1; i <= n; ++i)
    {
    	int digit = getDigit(i);
    	char* c = (char*)malloc(sizeof(char)*digit);

		if ((isMultipleOfN(i,3))&&(isMultipleOfN(i,5)))
    	{
    		result[i-1] = fizzBuzz;
    		continue;
    	}

    	if ((isMultipleOfN(i,3))&&(!isMultipleOfN(i,5)))
    	{
    		result[i-1] = fizz;    		
    		continue;

    	}

    	if (!(isMultipleOfN(i,3))&&(isMultipleOfN(i,5)))
    	{
    		result[i-1] = buzz;
    		continue;
    		
    	}

    	if (!(isMultipleOfN(i,3))&&(!isMultipleOfN(i,5)))
    	{
    		sprintf(c, "%d", i);
    		result[i-1] = c;
    	}

    }

    return result;
}