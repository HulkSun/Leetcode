/*
Author:HULK
Date : 2017-06-26 15:41:45
*/

/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int i,j;
    *columnSizes = (int *) malloc(sizeof(int) * numRows);
    int **triangle = (int**)malloc(sizeof(int*)*numRows);
    int *col ;

    for ( i = 0; i < numRows; ++i)
    {
    	col = (int*)malloc(sizeof(int)*(i+1));
	    *(*columnSizes+i) = i+1;
	    if(i == 0)
	    {
	    	col[0] = 1;
	    }
	    else 
	    	if(i == 1)
	    	{
	    		col[0] = 1;
	    		col[1] = 1;
	    	}
	    	else
	    	{
	    		col[0] = 1;
	    		col[i] = 1;
	    		for ( j = 1; j <= (i+1)/2; ++j)
	    		{
	    			col[j] = triangle[i-1][j] + triangle[i-1][j-1];
	    			col[i-j] = col[j];
	    		}
	    	}
	    for (j = 0; j <= i; ++j)
	    {
	    	printf("%d", col[j]);
	    }
	    printf("\n");
    	triangle[i] = col;
    }
    return triangle;
}