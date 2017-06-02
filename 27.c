/*author:HULK
* date:2017-05-24 11:16:44
*/

/*Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.*/

int removeElement(int* nums, int numsSize, int val) {
    int i,j;
    j = 0;
    for (i = 0; i < numsSize; ++i)
    {
    	if (nums[i] != val)
    	{
    		nums[j++] = nums[i];
    	}
    }
    return j;
}