/*author:HULK
* data:2017-04-14 19:43:27

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 2^31.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/
/*先异或，再数“1”*/
#include <stdio.h>

int hammingDistance(int x, int y) {
    int i;
    int z = x^y;
    int result = 0;
    for (i = 0; i < 32; ++i)
    {
    	result += (z&(1<<i))>>i;
    }
    return result;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", hammingDistance(9,7));
	return 0;
}


