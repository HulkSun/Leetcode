/*
Author:HULK
Date:2017-06-01 20:42:21
*/

/*Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.*/

int maxSubArray(int* nums, int numsSize) {
    int max = nums[0];
    int *dp = (int*)malloc(sizeof(int)*numsSize);
    dp[0] = nums[0];
    int i;
    for ( i = 1; i < numsSize; ++i)
    {
    	dp[i] = nums[i] + (dp[i-1]>0?dp[i-1]:0);
    	max = (max < dp[i])?dp[i]:max;
    }
    return max;
}