/*
* Author: hulk
* Date: 2017-07-04 16:16:51
*/
/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?*/

bool isAnagram(char* s, char* t) {
 	int count[26] = {0};
 	int i;
 	int len1 = strlen(s);
 	int len2 = strlen(t);
 	for (i = 0; i < len1; ++i)
 	{
 		count[s[i] - 'a']++;
 	}

 	for ( i = 0; i < len2; ++i)
 	{
 		count[t[i] - 'a']--;
 	}

 	for ( i = 0; i < 26; ++i)
 	{
 		if(count[i] != 0)return false;
 	}
 	return true;
}