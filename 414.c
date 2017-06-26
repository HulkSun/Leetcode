/*
Author:HULK
Date : 2017-06-26 19:49:48
*/

/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

int thirdMax(int* nums, int numsSize) {
    	
    long max1 = LONG_MIN;
    long max2 = LONG_MIN;
    long max3 = LONG_MIN;

    int i;

    for ( i = 0; i < numsSize; ++i)
    {
    	if(max1 < nums[i])max1 = nums[i];
    }
    printf("max1:%d\n",max1);
    for ( i = 0; i < numsSize; ++i)
    {
    	if( (max2 < nums[i]) && (nums[i] != max1) )max2 = nums[i];
    }
	printf("max2:%d\n",max2);
    for ( i = 0; i < numsSize; ++i)
    {
    	if( (max3 < nums[i]) && (nums[i] != max1) && (nums[i] != max2) ) max3 = nums[i];
    }
    printf("max3:%d\n",max3);
    if(max3 == LONG_MIN) return max1;
    return max3;
}
