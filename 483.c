/*
Author : HULK
Date ：2017-07-07 21:06:51
*/

/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    int len1 = strlen(s);
    int len2 = strlen(p);
    int* resultIndex = (int*)malloc(sizeof(int)*(len1));
    int hashTable[26] = {0};
    int i,j;
    for ( i = 0; i < len2; ++i)
    {
    	hashTable[p[i] - 'a']++;
    }

    int k = 0;
    for ( i = 0; i < len1 - len2 +1; ++i)
    {
    	int hashTable_2[26] = {0};
    	for ( j = i; j < i+len2; ++j)
    	{
    		hashTable_2[s[j] - 'a']++;
    	}

    	for ( j = 0; j < 26; ++j)
    	{
    		if(hashTable[j] != hashTable_2[j])break;
    	}
    	if(j == 26)resultIndex[k++] = i;
    }
    *returnSize = k;
    return resultIndex;
}