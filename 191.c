/*author:HULK
* data:2017-04-14 19:55:28
*/
/*
Total Accepted: 142489
Total Submissions: 365429
Difficulty: Easy
Contributor: LeetCode
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
#include <stdio.h>
#define uint32_t unsigned int
int hammingWeight(uint32_t n) {
    int i;
    int result = 0;
    for (i = 0; i < 32; ++i)
    {
    	result += (n&(1<<i))>>i;
    }
    return result;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", hammingWeight((uint32_t)7));
	return 0;
}
