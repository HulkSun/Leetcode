/*
author:HULK
data:2017-05-31 15:27:23
*/

/*Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int isIn(char** list, int listSize, char* restaurant)
{
	int i;
	for (i = 0; i < listSize; ++i)
	{
		if(strcmp(list[i], restaurant) == 0)return i;
	}
	return -1;
}

char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    int i,j;
    int *nums =(int*)malloc(sizeof(int)*list1Size);
    for ( i = 0; i < list1Size; ++i)
    {
    	nums[i] = -1;
    }
    for ( i = 0; i < list2Size; ++i)
    {
    	int index = isIn(list1, list1Size, list2[i]);
    	printf("index:%d\n",index);
    	printf("i:%d\n",i);
    	if( index != -1)
    	{
    		nums[index] = i;
    	}
    }
    
    for ( i = 0; i < list1Size; ++i)
    {
    	printf("统计:%d\n",nums[i]) ;
    }
    
    int minIndex = list1Size+list2Size+1;
    for ( i = 0; i < list1Size; ++i)
    {
    	if((nums[i] != -1) && ((i+nums[i])< minIndex))minIndex = i+nums[i];
    }

    (*returnSize) = 0;
    char** result = NULL;
    for (i = 0; i < list1Size; ++i)
    {
    	if ((nums[i] != -1) && (nums[i] + i == minIndex))
    	{
    		(*returnSize)++;
    		result = (char**)realloc(result ,sizeof(char*)*(*returnSize));
    		result[(*returnSize)-1] = list1[i];
    	}
    }

    return result;
}