/*
* Author: hulk
* Date: 2017-04-19 20:59:24
*/

/*Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
	if(head == NULL) return false;
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = *head;
    q = *head;
    while(p -> next != NULL && q->next->next!=NULL)
    {
    	p = p -> next;
    	q = q->next->next;
    	if(q == p) return true;
    }

    return false;
}