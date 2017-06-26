/*
Author:HULK
Date : 2017-06-26 17:50:29
*/

/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* getRow(int rowIndex, int* returnSize) {
     int i,j;
     int * result = (int*)malloc(sizeof(int)*(rowIndex+1));
     for ( i = 0; i <= rowIndex; ++i)
     {
     	result[i] = 0;
     }
     result[0] = 1;

     for ( i = 1; i <= rowIndex; ++i)
     {
     	for (j = i; j >= 1; --j)
     	{
     		result[j] += result[j-1];
     	}
     }
     *returnSize = rowIndex + 1;
     return result;
}