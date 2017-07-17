/*
Author:HULK
Date: 2017-07-13 16:26:27
*/
/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int MAD ;
int preValue;

int inOrder(struct TreeNode* root)
{
	if(root == NULL) return MAD;
    inOrder(root -> left);

    if(preValue != INT_MAX)
    {
    	MAD = MIN(MAD, (root -> val) - preValue);
    }

    preValue = root -> val;

    inOrder(root -> right);
    return MAD;
}

int getMinimumDifference(struct TreeNode* root) {

	MAD = INT_MAX;
	preValue = INT_MAX;
    return inOrder(root);
}