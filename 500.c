/*
* Author: hulk
* Date: 2017-04-17 11:25:01
*/
/*
Given a List of words, 
return the words that can be typed using letters of alphabet on only one row's of American keyboard 

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.*/


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

bool isIn(char* word)
{
	int i,key;
	char* a = "qwertyuiopQWERTYUIOP";
	char* b = "asdfghjklASDFGHJKL";
	char* c = "zxcvbnmZXCVBNM";

	char* keyBoard[3] = {a, b, c};
	
	for(key = 0 ; key < 3 ; key++)
	{
		if(strchr(keyBoard[key], word[0]) != NULL)break;
	}

	for (i = 1; i < strlen(word); ++i)
	{
		if(strchr(keyBoard[key], word[i]) == NULL) return false;
	}
	return true;

}

char** findWords(char** words, int wordsSize, int* returnSize) {
    int i,j;
    char* word;
    char** returnWords =  (char**)malloc(0);
    // char* returnWord =(char*)malloc(0);
    *returnSize = 0;
    j = 0;
    for (i = 0; i < wordsSize; ++i)
    {
    	word = words[i];
    	if (isIn(word))
    	{
    		(*returnSize)++;
    		// returnWord = (char*)realloc(returnWord, sizeof(char)*strlen(word));
    		// strcpy(returnWord, word);

    		returnWords = (char**)realloc(returnWords, sizeof(char*)*(j+1));
    		// returnWords[j++] = returnWord;
    		returnWords[j++] = word;
    	}
    }
    return returnWords;
}

int main(int argc, char const *argv[])
{
	int returnSize = 0;
	int wordsSize = 4;
	char* a = "hello";
	char* b = "Alaska";
	char* c = "world";
	char* d = "dad";

	char* words[4] = {a, b, c, d};
	char** result = findWords(words, wordsSize, &returnSize);
	int i;
	for (i = 0; i < returnSize; ++i)
	{
		printf("%s\n", result[i]);
	}

	return 0;
}
