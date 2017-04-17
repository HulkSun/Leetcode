/*
* Author: hulk
* Date: 2017-04-17 10:51:05
*/

/*Given a positive integer, output its complement number. 
The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), 
and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), 
and its complement is 0. So you need to output 0.*/
#include <stdio.h>
#include <math.h>

int findComplement(int num) {
    int mask = 0;
    int n = 0;
    while(n < 31)
    {
    	if(((num << n) >> 31)%2) break;
    	n++;
    }
    mask = pow(2,32-n)-1;
    return num^mask;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", findComplement(43690));
	return 0;
}


