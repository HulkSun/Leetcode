/*
* Author: hulk
* Date: 2017-07-13 14:57:15
*/

/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

*/

bool isPalindrome(char* s) {
    int len = strlen(s);
    if(len == 0) return true;
    char* stack = (char*)malloc(sizeof(char)*len);
    int i;
    int top = -1;
    for ( i = 0; i < len; ++i)
    {
    	if(( (s[i] >= 'a')&&(s[i] <= 'z'))||((s[i] >= 'A')&&(s[i] <= 'Z')) ||((s[i] >= '0')&&(s[i] <= '9')))
    	{
    		stack[++top] = s[i];
    	}
    }

    for ( i = 0; i < len; ++i)
    {
    	if(((s[i] >= '0')&&(s[i] <= '9')))
    	{
    		if(s[i] != stack[top]) return false;
    		else --top;
    	}
    	else 
    		if(( (s[i] >= 'a')&&(s[i] <= 'z'))||((s[i] >= 'A')&&(s[i] <= 'Z')))
	    	{
	    		if(!((s[i] == stack[top])||(s[i] == stack[top] - ('a' - 'A')) || (s[i] == stack[top] + ('a' - 'A'))))
	    			return false;
	    		else --top;
	    	}
    }

    return true;
}