/*
* Author: hulk
* Date: 2017-07-04 19:41:43
*/

/*Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int i ;
    int *resultNums = (int*)malloc(sizeof(int)*numsSize);
    for (i = 0; i < numsSize; ++i)
    {
    	if(nums[abs(nums[i]) - 1] > 0)nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
    }
    int j = 0;
    for (i = 0; i < numsSize; ++i)
    {
    	if(nums[i] > 0)resultNums[j++]=i+1;
    }

    *returnSize = j;
    return resultNums;
}