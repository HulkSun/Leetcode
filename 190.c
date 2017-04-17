/*author:HULK
* data:2017-04-14 20:05:33
*/

/*Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
 return 964176192 (represented in binary as                 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?
*/

/*二进制两边比较，不相同就翻转*/
#include <stdio.h>
#include <stdint.h>
uint32_t reverseBits(uint32_t n) {
    uint32_t i,j;
    uint32_t result = n;
    for(i = 0 , j = 31 ; i < j ; i++ , j--)
    {

    	if ((((1<<i)&n)>>i) !=  (((1<<j)&n)>>j))
    	{
    		result ^= (1<<i);
    		result ^= (1<<j);
    	}
    }
    return result;
}


int main(int argc, char const *argv[])
{
	printf("%u\n", reverseBits((uint32_t)43261596));
	return 0;
}
