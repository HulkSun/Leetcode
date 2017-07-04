/*
Author:HULK
Date : 2017-06-27 09:29:01
*/

// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree(int* nums, int start, int end)
{
	if(start > end) return NULL;
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	int middle = (start+end)/2;
	node -> val = nums[middle];
	node -> left = buildTree(nums,start,middle-1);
	node -> right = buildTree(nums, middle+1,end);
	return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if(numsSize == 0) return NULL;
    return buildTree(nums,0,numsSize-1);
}
