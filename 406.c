/*
Author: HULK
Date: 2017-07-16 12:59:47
*/

/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
算法思想：
	1.选出最高、次高、第三高.....的人，相同身高内按k排序，存在sub[][]内
	2.按身高为顺序对每一个人进行如下操作：将第i个人插入到当前序列的第sub[i][1]的位置上。
*/
int** reconstructQueue(int** people, int peopleRowSize, int peopleColSize, int* returnSize) {
    int i,j;
    int** result = (int**)malloc(sizeof(int*)*peopleRowSize);
    
    for ( i = 0; i < peopleRowSize; ++i)
    {
    	result[i] = (int*)malloc(sizeof(int)*peopleColSize);
    }

	int** sub = (int**)malloc(sizeof(int*)*peopleRowSize);
    
    for ( i = 0; i < peopleRowSize; ++i)
    {
    	sub[i] = (int*)malloc(sizeof(int)*peopleColSize);
    }

    int k = 0;
    
    int pre_tallest;
    while(k < peopleRowSize)
    {
    	int tallest = INT_MIN;
    	if(k == 0)
    	{
    		for ( i = 0; i < peopleRowSize; ++i)
	    	{
	    		if(people[i][0] > tallest ) tallest = people[i][0];
	    	}	
    	}
    	else 
    	{
    		for ( i = 0; i < peopleRowSize; ++i)
	    	{
	    		if(people[i][0] > tallest && (people[i][0] < pre_tallest)) tallest = people[i][0];
	    	}	
    	}
    	printf("tallest:%d\n",tallest);
	    pre_tallest = tallest;
	    int pre_k = k;
	    for ( i = 0; i < peopleRowSize; ++i)
	    {
	    	if(people[i][0] == tallest)
	    	{
	    		sub[k][0] = people[i][0]; 
	    		sub[k][1] = people[i][1]; 
	    		k++;
	    	}
	    }
	    for ( i = pre_k; i < k - 1 + pre_k; ++i)
	    {
	    	for ( j = pre_k; j < k - i - 1 + pre_k; ++j)
	    	{
	    		if(sub[j][1] > sub[j+1][1])
	    		{
	    			int tmp = sub[j][1] ;
	    			sub[j][1]  = sub[j+1][1];
	    			sub[j+1][1]  = tmp;  
	    		}
	    	}
	    }
        for ( i = pre_k; i < k; ++i)
        {
            printf("I:%d %d %d\n", i,sub[i][0], sub[i][1]);
        }
    }
   

	for ( i = 0; i < peopleRowSize; ++i)
	{
		printf("%d %d\n", sub[i][0], sub[i][1]);
	}
    
    for ( i = 0; i < peopleRowSize; ++i)
    {
    	if(i == 0)
    	{
    		result[i][0] = sub[i][0];
    		result[i][1] = sub[i][1];
    	}
    	else
    	{
    		int j;
    		for ( j = i-1; j >= sub[i][1]; --j)
    		{
    			result[j+1][0] = result[j][0];
    			result[j+1][1] = result[j][1];
    		}

    		result[sub[i][1]][0] = sub[i][0];
    		result[sub[i][1]][1] = sub[i][1];
    	}
    }

    

    *returnSize = k;
    return result;
}