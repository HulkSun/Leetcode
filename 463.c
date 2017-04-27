/*
* Author: hulk
* Date: 2017-04-25 08:51:40
*/

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int i,j;
    int count_1 = 0;
    int count_nebor = 0;
    for ( i = 0; i < gridRowSize; ++i)
    {
    	for ( j = 0; j < gridColSize; ++j)
    	{
    		count_1 += grid[i][j];
    		if(grid[i][j])
    		{
    			if(j < gridColSize-1)count_nebor += grid[i][j+1];
    			if(i < gridRowSize-1)count_nebor += grid[i+1][j];
    		}
    	}
    }
    return count_1*4 - count_nebor*2;
} 