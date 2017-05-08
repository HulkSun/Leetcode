/*
* Author: hulk
* Date: 2017-04-28 16:31:59
*/

// Implement strStr().

// Returns the index of the first occurrence of needle in haystack,
// or -1 if needle is not part of haystack.

int strStr(char* haystack, char* needle) {
    if(strlen(needle) == 0)return 0;
    int i,j,k;
    for ( i = 0; i < strlen(haystack); i++)
    {
    	if(i + strlen(needle) > strlen(haystack))return -1;
    	for ( j = 0, k = i; j < strlen(needle); j++, k++)
    	{
    		if(haystack[k] != needle[j])break;
    		if(j == strlen(needle)-1) return i;
    	}
    	
    }
    return -1;
}