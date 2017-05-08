/*
* Author: hulk
* Date: 2017-05-08 17:25:57
*/

/*Given a positive integer num, write a function which returns True 
if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False*/



bool isPerfectSquare(int num) {
    int i = 1;
    while(i <= num)
    {
    	num -= i;
    	i += 2;
    }
    return (num == 0) ;
}