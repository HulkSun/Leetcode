/*
* Author: hulk
* Date: 2017-04-19 16:57:21
*/

/*
Given a string which consists of lowercase or uppercase letters, 
find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.*/
#include <stdio.h>
#include <string.h>



int longestPalindrome(char* s) {
    int length = strlen(s);
    int i;
    int index;
    int count[52]={0};
    int result = 0;
    for (i = 0; i < length; ++i)
    {
    	if (s[i] >= 'a' && s[i] <= 'z')
    	{
    		index = s[i] - 97;
    	}

    	if (s[i] >= 'A' && s[i] <= 'Z')
    	{
    		index = s[i] - 65 + 26;
    	}
    	count[index]++;
    }

    for ( i = 0; i < 52; ++i)
    {
    	printf("%d\n", count[i]);
    	result += count[i]/2;
    }

    result *= 2;
    if (length > result)
    {
    	result++;
    }
    return result;
}

int main(int argc, char const *argv[])
{
	char* s = "abccccdd";
	printf("%d\n", longestPalindrome(s));
	return 0;
}