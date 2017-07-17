/*
Author:HULK
Date ： 2017-07-15 09:25:28
*/
/*
Given a singly linked list L: L0?L1?…?Ln-1?Ln,
reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {

	if(head == NULL || head -> next == NULL) return NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* pre_middle = (struct ListNode*)malloc(sizeof(struct ListNode));
    pre_middle -> next  = head;;
    while(fast!= NULL && fast -> next != NULL)
    { 
    	pre_middle  = pre_middle -> next;
    	slow = slow-> next;
    	fast = fast -> next -> next;
    }

    struct ListNode* start = slow;
    struct ListNode* then  = start -> next;

    printf("start:%d\n",start->val);
    while(then != NULL)
    {
    	start -> next = then -> next;
    	then -> next = pre_middle -> next;
    	pre_middle -> next = then;
    	then = start -> next;
    }

    /*struct ListNode* tmp = head;
    while(tmp != NULL)
    {
    	printf("%d -> ",tmp->val);
    	tmp = tmp -> next;
    }*/

    struct ListNode* p = head;
    struct ListNode* q = pre_middle -> next;

    while(p != pre_middle)
    {
    	pre_middle -> next = q -> next;
    	q -> next = p -> next;
    	p -> next = q;
    	p = q -> next;
    	q = pre_middle -> next;
    }
   
}