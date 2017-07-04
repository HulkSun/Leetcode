/*
* Author: hulk
* Date: 2017-07-04 16:05:59
*/

/*Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
Note: The merging process must start from the root nodes of both trees.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if(t1 == NULL && t2 == NULL) return NULL;
    struct TreeNode* mergeTree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    mergeTree->val = (t1 == NULL ? 0 : t1 -> val) + (t2 == NULL ? 0 : t2 -> val);
    mergeTree -> left = mergeTrees((t1 == NULL) ? NULL : t1 -> left, (t2 == NULL) ? NULL : t2 -> left);
    mergeTree -> right = mergeTrees((t1 == NULL) ? NULL : t1 -> right, (t2 == NULL) ? NULL : t2 -> right);
    return mergeTree;
}