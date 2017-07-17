/*
Author:HULK
Date:2017-06-06 10:01:08
*/

/*Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False*/

bool detectCapitalUse(char* word) {
    int length = strlen(word);
    int upperCount = 0;
    int i;
    for ( i = 0; i < length; ++i)
    {
    	if(word[i] <= 'Z' && word[i] >= 'A')upperCount++;
    }

    if(upperCount == 0 || upperCount == length) return true;
    else 
    	if(upperCount == 1 && (word[0] <= 'Z' && word[0] >= 'A')) return true;
    	else return false;
}