/*
* Author: hulk
* Date: 2017-04-18 19:25:40
*/

/*You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

*/

int climbStairs(int n) {
    if (n > 1)
    {
    	return climbStairs(n-1)+climbStairs(n-2);
    }
    else return 1;
}