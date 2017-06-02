/*
* Author: hulk
* Date: 2017-05-11 20:12:32
*/


/*Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/

int maxDepth(struct TreeNode* root) {
    if(root == NULL) return 0;
    int m = (root -> left == NULL)?0:maxDepth(root -> left) ;
    int n = (root -> right == NULL)?0:maxDepth(root -> right);
	// return m>n?(m+1):(n+1);
	return (m>n?m:n)+1;

}