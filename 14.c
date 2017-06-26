/*
Author:HULK
Date: 2017-06-26 10:48:43
*/

/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0)return "";
    if(strsSize == 1)return strs[0];
    int i,j;
    char *prefix = (char*)malloc(sizeof(char)*strlen(strs[0]));
    prefix[0] = '\0';
    for ( i = 0; i < strlen(strs[0]); ++i)
    {
    	for ( j = 1; j < strsSize; ++j)
    	{
    		if(strs[j][i] != strs[0][i])
            {
            	prefix[i] = '\0';
    			return prefix;
            }
    	}
    	prefix[i] = strs[0][i];
    }
    prefix[i] = '\0';
    return prefix;
}