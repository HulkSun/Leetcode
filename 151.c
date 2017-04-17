/*
* Author: hulk
* Date: 2017-04-12 17:08:16
*/

/*Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.*/

/*
	解题思路：先整体翻转，再单词翻转
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

void reverse(char* s) {
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
}

void reverseSentance(char *s) {
    int length = strlen(s);
    int i,j;
    char tmp;
    for ( i = 0, j = length-1; i < j; i++, j--)
    {
    	tmp = s[i];
    	s[i] = s[j];
    	s[j] = tmp;
    }
}



void reverseWords(char *s) {
    reverseSentance(s);
    reverse(s);
    return s;
}
