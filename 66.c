/*
* Author: hulk
* Date: 2017-04-28 09:56:36
*/
/*Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    int i = digitsSize-1;
    int j = 0;
    if(digits[i] != 9)
    {
    	int* result = (int*)malloc(sizeof(int)*digitsSize);
    	result[i] = digits[i] +1;
    	i--;
    	while(i >= 0) 
    	{
    	    result[i] = digits[i];
    	    i--;
    	}
    	*returnSize = digitsSize;
    	return result;
    }
    while(i >= 0)
    {
    	i--;
    	if(digits[i] != 9)break;
    	
    }
    j = i;
    if (i ==  -1)
    {
    	int* result = (int*)malloc(sizeof(int)*(digitsSize+1));
    	j = digitsSize;
    	while(j)result[j--] = 0;
    	result[j] = 1;
	   	*returnSize = digitsSize+1;
    	return result;
    }
    else
    {
    	int* result = (int*)malloc(sizeof(int)*digitsSize);
    	i = j+1;
    	while(i < digitsSize)result[i++] = 0;
    	result[j] = digits[j] + 1;
    	j--;
    	while(j >= 0) 
    	{
    	    result[j] = digits[j];
    	    j--;
    	}
    	*returnSize = digitsSize;
    	return result;
    }
}