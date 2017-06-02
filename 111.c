/*
* Author: hulk
* Date: 2017-05-11 20:33:33
*/

/*Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.*/

int minDepth(struct TreeNode* root) {
    if(root == NULL) return 0;
    if(root -> left == NULL) return 1+minDepth(root->right);
    else 
    	if(root -> right == NULL) return 1+minDepth(root->left);
    	else 
    	{
    		int m = minDepth(root -> left) ;
   			int n = minDepth(root -> right);
			// return m>n?(m+1):(n+1);
			return (m>n?n:m)+1;
    	}
}