/*
* Author: hulk
* Date: 2017-05-11 19:25:16
*/

/*Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root) 
    {
        invertTree(root->left);
        invertTree(root->right);
    	struct TreeNode* p = root -> right;
   	 	root -> right = root -> left;
    	root -> left = p;
    }
    return root;
}