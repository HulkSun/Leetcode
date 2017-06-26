/*
Author:HULK
Date : 2017-06-26 20:35:45
*/

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

void sort(int *nums, int length)
{
	int i,j;
	for ( i = 0; i < length - 1; ++i)
	{
		for (j = 0; j < length - i - 1; ++j)
		{
			if(nums[j] > nums[j+1])
			{
				int tmp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = tmp;
			}
		}
	}
}

int findKthLargest(int* nums, int numsSize, int k) 
{
    sort(nums,numsSize);
    return nums[numsSize-k];
}