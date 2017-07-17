/*
Author:HULK
Date ： 2017-07-16 15:13:51
*/

/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum = 0;

void convert(struct TreeNode* root)
{
	if(root == NULL) return ;
	convert(root->right);
	root -> val += sum;
	sum = root -> val;
	convert(root -> left);
}

struct TreeNode* convertBST(struct TreeNode* root) {
    sum = 0;
    convert(root);
    return root;
}