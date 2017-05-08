/*
* Author: hulk
* Date: 2017-05-08 20:17:20
*/

/*Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */struct ListNode* reverse(struct ListNode* head)
{
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


bool isPalindrome(struct ListNode* head) {
	if(head == NULL || head -> next == NULL )return true;
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while(fast != NULL && fast -> next != NULL)
	{
		fast = fast -> next -> next;
		slow = slow -> next;
	}

	if (fast != NULL)
	{
		slow = slow -> next;
	}

	slow = reverse(slow);
	fast = head;

	while(slow != NULL)
	{
		if (fast -> val != slow -> val)
		{
			return false;
		}
		fast = fast -> next;
		slow = slow -> next;
	}
	return true;
}