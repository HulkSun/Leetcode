/*
* Author: hulk
* Date: 2017-04-11 21:20:20
*/

/*Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
*/

#include <stdio.h>
#include <string.h>

void reverseWord(char* s, int i, int j) {
	char tmp;
    j = j-1;
    // printf("%d %d\n", i,j);
    for(; i < j ; i++, j--)
    {
    	// printf("%c %c\n", s[i], s[j]);

       tmp = s[i];
       s[i] = s[j];
       s[j] = tmp;
    }
}

char* reverseWords(char* s) {
    int i = 0, j = 0;
    int p = 0, q = 0;
    while(s[p]!='\0')
    {
    	printf("p:%d\n", p);
        while(s[j]!=' ' && s[j]!='\0')j++;
        reverseWord(s, i, j);
        p = j;
        i = ++j;
    }
    return s;
}

int main(int argc, char const *argv[])
{
	char* s = "Hello world!";
	printf("%s\n", s);
	reverseWords(s);
	printf("%s\n", s);
	return 0;
}