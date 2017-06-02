/*author:HULK
* date:2017-05-24 14:39:13
*/
/*Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?*/

bool isPowerOfFour(int num) {
    if(num == 1) return true;
    return ( !(num & (num - 1)) && !((num - 1)%3) );
}