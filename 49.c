/*
* Author: hulk
* Date: 2017-05-08 17:24:12
*/

// Implement int sqrt(int x).

// Compute and return the square root of x.

//牛顿法解方程：x^2 = a

int mySqrt(int x) {
    long x_k = x;
    while(x_k*x_k > x)
    {
        x_k = (x_k*x_k + x)/(2*x_k);
    }
    return x_k;
}