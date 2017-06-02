/*
Author:HULK
Date:2017-06-01 10:12:39
*/

/*Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input: 
         1
       /   \
      2     3
Output: 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };

 */
int result;

int postOrder(struct TreeNode* root)
{
	if(root == NULL) return 0;
	int left = postOrder(root -> left);
	int right = postOrder(root -> right);
	result += ((left - right) > 0)?(left - right):(right - left);
	return left + right + root -> val;
}

int findTilt(struct TreeNode* root) {
	result = 0;
	postOrder(root);
	return result;
}
