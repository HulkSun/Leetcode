/*author:HULK
data:2017-04-13 20:43:23
*/

/*Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]*/

void reverse(int* nums, int start, int end)
{
	while(start < end)
	{
		int tmp = nums[start];
		nums[start++] = nums[end];
		nums[end--] = tmp;
	}		
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
    
}