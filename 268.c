/*
* Author: hulk
* Date: 2017-04-12 21:14:37
*/

/*Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. 
Could you implement it using only constant extra space complexity?

The basic idea is to use XOR operation. We all know that a^b^b =a, 
which means two xor operations with the same number will eliminate the number and reveal the original number.
*/

#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    int i;
    int result =0;
    for (i = 0; i < numsSize; ++i)
    {
    	result = result^nums[i]^i;
    }
    return result^i;
}

int main(int argc, char const *argv[])
{
	int nums[10] = {0,1,10,3,4,5,6,7,8,2};
	printf("%d\n", missingNumber(nums,10));
 	return 0;
}