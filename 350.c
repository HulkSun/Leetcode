/*
Author:HULK
Date:2017-06-26 14:55:11
*/

/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void sort(int* nums, int length)
{
	int i,j;
	for (i = 0; i < length - 1; ++i)
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

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    sort(nums1, nums1Size);
    sort(nums2, nums2Size);

    int * result = (int*)malloc(sizeof(int)*(nums1Size < nums2Size ? nums1Size : nums2Size));

    int i = 0,j = 0, k = 0;
    while(i < nums1Size && j < nums2Size )
    {
    	if(nums1[i] < nums2[j]) i++;
    	else if( nums1[i] > nums2[j]) j++;
    		 else 
    		 {
    		 	result[k++] = nums1[i];
    		 	i++;j++;
    		 }
    }
    (*returnSize) = k;
    return result;
}