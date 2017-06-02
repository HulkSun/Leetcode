/*author:HULK
* date:2017-05-25 16:14:13
*/
/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.*/

int firstUniqChar(char* s) {
    int count[26] = {0};
    int i = 0;
    while(s[i] != '\0')
    {
    	count[s[i] - 'a'] ++ ;
    	i++;
    }
    i = 0;
    while(s[i] != '\0')
    {
    	if(count[s[i] - 'a'] == 1) return i;
    	i++;
    }
    return -1;
}