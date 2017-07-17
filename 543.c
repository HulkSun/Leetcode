/*
Author:HULK
Date: 2017-07-11 21:01:46
*/

/*Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a,b) ((a>b)?(a):(b))

int maxDiameter;

int MaxDepth(struct TreeNode* root)
{
	if(root == NULL) return 0;
	int left = MaxDepth(root->left);
	int right = MaxDepth(root -> right);
	int curDiameter =left+right;
	maxDiameter = MAX(maxDiameter,curDiameter);
	return MAX(left, right)+1;
}



int diameterOfBinaryTree(struct TreeNode* root) {
    maxDiameter = 0;
    MaxDepth(root);
	return  maxDiameter;
}