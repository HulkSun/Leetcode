/*
* Author: hulk
* Date: 2017-04-27 21:07:30
*/

// Merge two sorted linked lists and return it as a new list.
// The new list should be made by splicing together the nodes of the first two lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l2 == NULL)return l1;
    if(l1 == NULL)return l2;
    if (l1 -> val < l2 -> val)
    {
    	l1 -> next = mergeTwoLists(l1 -> next, l2);
    	return l1;
    }
    else
    {
    	l2 -> next = mergeTwoLists(l2, l1 -> next);
    	return l2;
    }
}*/

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* q = p;
    while(l1  != NULL && l2  != NULL)
    {
    	if (l1 -> val < l2 -> val)		
    	{
    		p -> next = l1;
    		l1 = l1 -> next;
    	}
    	else 
    	{
    		p -> next = l2;
    		l2 = l2 -> next;
    	}
    	p = p-> next;
    }
 	while(l1  != NULL)
 	{
 		p -> next = l1;
    	l1 = l1 -> next;
    	p = p-> next;
 	}

	while(l2  != NULL)
 	{
 		p -> next = l2;
    	l2 = l2 -> next;
    	p = p-> next;
 	}
 	 	return q->next;

}