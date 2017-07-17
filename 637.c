/*
Author:HULK
Date: 2017年7月13日15:24:43
*/
/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.*/

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

#define MAX(a,b) ((a)>(b)?(a):(b))


int getDepth(struct TreeNode* root)
{
	if(root == NULL) return 0;
	return MAX(getDepth(root -> left),getDepth(root -> right))+1;
}

void BFS(struct TreeNode *root, double* result, int level)
{
	if(root == NULL) 
	{
		return;
	}

	struct TreeNode **queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*(pow(2,level)));
	int head = 0;
	int tail = 0;
	int curLevel = 0;
	queue[tail++] = root;
	while(head != tail)
	{
		int i;
		double sum = 0.0;
		int n = tail - head;
		for ( i = 0; i < n; ++i)
		{
			sum += queue[head] -> val;
			if(queue[head] -> left != NULL) queue[tail++] = queue[head] -> left;
			if(queue[head] -> right != NULL) queue[tail++] = queue[head] -> right;
			head++;
		}
		sum /= n;
		result[curLevel++] = sum;
	} 
	free(queue);
}

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    *returnSize = getDepth(root);
    double* result = (double*)malloc(sizeof(double)*(*returnSize));
    BFS(root, result,*returnSize);
    return result;
}