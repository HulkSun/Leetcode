/*
* Author: hulk
* Date: 2017-04-27 20:32:54
*/

// Given an array of integers that is already sorted in ascending order, 
// find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers 
// such that they add up to the target, where index1 must be less than index2. 
// Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution 
// and you may not use the same element twice.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    (*returnSize) = 2;
    int i , j;
    int flag = 0;
    int* result = (int*)malloc(sizeof(int)*2) ;
    for(i = 0; i < numbersSize ; i ++)
    {
        // if(numbers[i] > target) break;
        for(j = i+1 ; j < numbersSize ; j ++)
        {
            // if(numbers[j] > target) break;
            if(numbers[i] + numbers[j] == target)
            {
                result[0] = i+1;
                result[1] = j+1;
                flag = 1;
                break;
            }
            if(flag)break;
        }
    }
       return result;
}