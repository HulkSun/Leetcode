/*
Author：HULK
Date :　2017-07-11 19:46:22
*/
/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int max;
int min;
int l;
int* inOrderCount = NULL;

void inOrder_getMaxandMin(struct TreeNode* root)
{
	if(root != NULL)
	{
		inOrder_getMaxandMin(root -> left);
		int val = root -> val;
		if(val > max)max = val;
		if(val < min)min = val;
		inOrder_getMaxandMin(root -> right);
	}
}

void inOrder_Count(struct TreeNode* root)
{
	if(root != NULL)
	{
		inOrder_Count(root -> left);
		inOrderCount[root->val - min]++;
		inOrder_Count(root -> right);
	}
}

int* findMode(struct TreeNode* root, int* returnSize) {
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    max = INT_MIN;
    min = INT_MAX;
    inOrder_getMaxandMin(root);
    printf("%d\n", max);
    printf("%d\n", min);
    int len = max - min + 1;
    inOrderCount = (int*)malloc(sizeof(int)*len);
    memset(inOrderCount,INT_MIN,sizeof(int)*len);
    inOrder_Count(root);
    int i;
    int max_index = 0; 
    for ( i = 0; i < len; ++i)
    {
    	if(inOrderCount[i] > inOrderCount[max_index]) max_index = i;
    }
    printf("max_index:%d\n",max_index);
    int* result = (int*)malloc(sizeof(int)*len);
    int k = 0;
    for (i = 0; i < len; ++i)
    {
        printf("%d\n", inOrderCount[i]);
    	if(inOrderCount[i] == inOrderCount[max_index])
    	{
    		result[k++] = i+min;
    	} 
    }
    free(inOrderCount);
    *returnSize = k;
    return result;
}