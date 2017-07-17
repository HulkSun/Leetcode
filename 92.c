/*
Author:HULK
Date ： 2017-07-15 08:26:54
*/

/*Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 <= m <= n <= length of list.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if(head == NULL) return NULL;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy -> next = head;
    struct ListNode *pre = dummy;
    int i;
    for (i = 0; i < m-1; ++i)
    {
    	pre = pre -> next;
    }

    struct ListNode *start = pre -> next;
    struct ListNode *then = start -> next;

    for ( i = 0; i < n-m; ++i)
    {
    	start -> next = then -> next;
    	then -> next = pre -> next;
    	pre -> next = then;
    	then = start -> next;
    }
    return dummy -> next;

}