/*
* Author: hulk
* Date: 2017-04-19 14:43:01
*/
/*
Given scores of N athletes, 
find their relative ranks and the people with the top three highest scores, 
who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, 
so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.*/

#include <stdio.h>
#include <malloc.h>

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
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* nums, int numsSize, int* returnSize) {
    (*returnSize) = numsSize;
    int* ranks = (int*)malloc(sizeof(int)*numsSize);
    int i,j;
    int max_index = 0;
    for (i = 0; i < numsSize; i++)
    {
    	max_index = i;
    	for (j = 0 ; j < numsSize; j++)
    	{
    		if(nums[j] > nums[max_index]) max_index = j;
    	}
    	// max_value = nums[max_index];

    	// for(j = max_index ; j > i ; j--)
    	// {
    	// 	nums[j] = nums[j-1];
    	// }
    	nums[max_index] = -1;
    	ranks[i] = max_index;

    	// printf("%d\n", max_index);
    }

    char** result = (char**)malloc(sizeof(char*)*numsSize);

    for (i = 0; i < numsSize; ++i)
    {	
    	if(i == 0)	(result[ranks[0]]) = "Gold Medal";

    	else if (i == 1)	(result[ranks[1]]) = "Silver Medal";

    		else if(i == 2)	(result[ranks[2]]) = "Bronze Medal";

    			else
    			{
    				j = i+1;
			    	int digit = getDigit(j);
			    	char* c = (char*)malloc(sizeof(char)*digit);

			    	sprintf(c, "%d", j);
			    	(result[ranks[i]]) = c;
    			}

    	
    }

    // for (i = 0; i < numsSize; ++i)
    // {
    // 	printf("%s\n", result[i]);

    // }
    return result;
}

int main(int argc, char const *argv[])
{
	int nums[5] = {1,4,3,2,5};
	int returnSize = 0;;
	findRelativeRanks(nums,5,&returnSize);
	return 0;
}