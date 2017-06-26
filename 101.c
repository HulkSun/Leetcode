/*
* Author: HULK
* Date: 2017-04-27 20:28:22
*/
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
   */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool charge(struct TreeNode* left, struct TreeNode* right)
{
	if(left == NULL && right == NULL) return true;
	if(left != NULL && right == NULL) return false;
	if(left == NULL && right != NULL) return false;

	if(left->val != right -> val) return false;

	return charge(left -> left, right -> right) && charge(left -> right, right ->left);
}

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL) return true;
    return charge(root -> left, root -> right);
}