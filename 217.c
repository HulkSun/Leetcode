/*
* Author: hulk
* Date: 2017-06-28 21:02:13
*/

/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

*/

int partition(int arr[], int low, int high){
    int key;
    key = arr[low];
    while(low<high){
        while(low <high && arr[high]>= key )
            high--;
        if(low<high)
            arr[low++] = arr[high];
        while( low<high && arr[low]<=key )
            low++;
        if(low<high)
            arr[high--] = arr[low];
    }
    arr[low] = key;
    return low;
}
void quick_sort(int arr[], int start, int end){
    int pos;
    if (start<end){
        pos = partition(arr, start, end);
        quick_sort(arr,start,pos-1);
        quick_sort(arr,pos+1,end);
    }
    return;
}

void sort(int *nums, int length)
{
	quick_sort(nums,0,length-1);
}

bool containsDuplicate(int* nums, int numsSize) {
    sort(nums,numsSize);
    int i ;
    for (i = 1; i < numsSize; ++i)
    {
    	if(nums[i] == nums[i-1])return true;
    }
    return false;
}