/*
Author:HULK
Date:2017-06-26 09:44:17
*/

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p = head;
    int carry = 0;
    int sum = 0;
    while(l1 != NULL || l2 != NULL)
    {
    	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    	if(l1 != NULL && l2 != NULL)
		{
			sum = l1 -> val + l2 -> val + carry;
			l1 = l1 -> next;
			l2 = l2 -> next;
		}
		else if(l1 == NULL && l2 != NULL)
			{
				sum = l2 -> val  + carry;
				l2 = l2 -> next;
			}
			else /*if(l1 != NULL && l2 == NULL)*/
			{
				sum = l1 -> val + carry;
				l1 = l1 -> next;
			}
    	node -> val = sum % 10;
    	carry = sum / 10;
    	p -> next = node;
    	p = p -> next;
    }
    if(carry == 1)
    {
    	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    	node -> val = 1;
    	p -> next = node;
    	p = p -> next;
    }
    p -> next = NULL;
    return head->next;
}