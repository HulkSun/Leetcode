/*author:HULK
* date:2017-05-22 09:59:13
*/

/*Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.

Example 1:
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 
Example 2:
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one kind of candies. */

int distributeCandies(int* candies, int candiesSize) {
    int i ,j;
    int kindSize = candiesSize;
    //sort
    for ( i = 0; i < candiesSize -1; ++i)
    {
    	for ( j = 0; j < candiesSize - i -1; ++j)
    	{
    		if(candies[j] > candies[j+1])
    		{
    			int tmp = candies[j];
    			candies[j] = candies[j+1];
    			candies[j+1] = tmp;
    		}
    	}
    }

    for ( i = 0; i < candiesSize - 1; ++i)
    {
    	if(candies[i] == candies[i+1]) kindSize --;
    }
    //if(candies[candiesSize - 1] == candies[candiesSize - 2]) kindSize -- ;

    if(kindSize > candiesSize/2) return candiesSize/2;
    else return kindSize; 
}