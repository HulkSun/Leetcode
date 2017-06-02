/*author:HULK
* date:2017-05-24 15:09:11
*/

/*Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?*/

bool isPowerOfThree(int n) {
    if(n <= 0) return false;
    if(n == 1) return true;
    int flag = 0;
    while(n > 1)
    {
    	flag += n%3;
    	n /= 3;
    }
    return flag?false:true;
}