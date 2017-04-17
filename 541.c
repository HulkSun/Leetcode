/*
* Author: hulk
* Date: 2017-04-12 15:46:15
*/


/*
Given a string and an integer k, 
you need to reverse the first k characters for every 2k characters 
counting from the start of the string. If there are less than k characters left, 
reverse all of them. If there are less than 2k but greater than or equal to k characters, 
then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/
#include <stdio.h>
#include <string.h>

void reverseWord(char* s, int i, int j) {
	char tmp;
    printf("%d %d\n", i,j);
    for(; i < j ; i++, j--)
    {
    	printf("%c %c\n", s[i], s[j]);

       // tmp = s[i];
       // s[i] = s[j];
       // s[j] = tmp;
    }
}

char* reverseStr(char* s, int k) {
    int i,j,p;
    int length = strlen(s);
    // printf("length:%d\n", length);
    if (length < k)
    {
    	reverseWord(s,0,length-1);
    }
    else
        if(length < 2*k)
        {
            reverseWord(s,0,k-1);
        }
        else
        {
        	i = 0;
        	j = k-1;
        	p = 2*k-1;
        	while(p <= length)
        	{
        		reverseWord(s,i,j);
        		i += 2*k;
        		j += 2*k;
        		p += 2*k;
        	}

    		if(j < length)reverseWord(s,i,j);
    		else reverseWord(s,i,length-1);
    
        }
        return s;
}
int main(int argc, char const *argv[])
{
	char* s = "uxzpsogzkwgwacxxvvzlhkaahjaqagdfjkmyutvhxclzskvxckjvfgzptlzldjwhrpocfugzqkpaxexezbvggtkoxriysqivupofrcoxbrdgccvphvdtvrjtsbospmgyfduvaslnvxwuepleziodaaqmonsxjszyjwjmvgdqgowjjtwdmynvirnlujimedfyntgacntvyqujvehhvruiolfkeprqpzdvmapeukemmzxdtyolxeixatgsupvpidmeyifjyxkzudxvsunghtklzgxsjhrxgxgqcdebukrarpkpqmusempvulagashxpaisfvetrmiqiordsyjgyjmkvavxorrmnxbiikuxmezpkhgkjzmapldnmjvfxtmckskiwhdnuqpqrsrdspxuixxnibjxoyagijmlbhjtuchzbdpaxommfvlbpxfnzkkcdentdhhxracunvrtqxrbqanufaglncjqiwofanuznfmbtjalehlqidtcmqbsgppqyoaoglifareljluigqyxtveukstzepridpmdltpxjmzdvatgzmqexrauywreoslyoydmiyipyqiaihfjqncelefiaxjhdaamrvahbvoznsfvsdknlktsifioxjdsqldzlyzqkqxkwjfrehqbhlaanbcvxomxyypqfxbwmtaiegcjlzeslmpghirzsaprxdcbobflvbupwahxwjgrcqskewvjsjyyggozkvwwytrwpmuguclssmrshlwukkjapiwnkybydergdqkhttbakooghbskiqlesocfrjuxotecnhkfmwtmzcysppmffnskvfabunfzsibqrerfstonzjhtcpnscpteflsnmqqphelpngnlnczritcjxewlhftujrpaeaxylqkswaisvzgciaemvodvcnqtuwcjkmzjzkikaqifymwwlvyxndgwwlauwiyiflgoahyaavkudvemfftzwlxdltwicouwboeaddxmvind";
	printf("%s\n", s);
	reverseStr(s,22);
	printf("%s\n", s);
	return 0;
}