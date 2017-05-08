/*
* Author: hulk
* Date: 2017-05-08 20:47:49
*/

/*
Reverse a singly linked list.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
   	struct ListNode* pre = NULL;
	while(head != NULL)
	{
		struct ListNode* next = head -> next;
		head -> next = pre;
		pre = head;
		head = next;
	}
	return pre; 
}