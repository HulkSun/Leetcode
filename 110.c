/*
* Author: hulk
* Date: 2017-07-04 17:09:05
*/
/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root)
{
	if(root == NULL) return 0;
	int leftDepth = maxDepth(root -> left);
	int rightDepth = maxDepth(root -> right);
	return (( leftDepth > rightDepth )? leftDepth : rightDepth ) + 1;
}

bool isBalanced(struct TreeNode* root) {
	if(root == NULL) return true;
    int diff = maxDepth(root -> left) - maxDepth(root -> right);
    return (abs(diff) < 2) && (isBalanced(root -> left)) && (isBalanced(root -> right)); 
}