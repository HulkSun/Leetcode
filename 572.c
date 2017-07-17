/*
Author :ＨＵＬＫ
date : 2017-07-07 20:29:33
*/

/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSame(struct TreeNode* s, struct TreeNode* t)
{
	if(s == NULL && t == NULL) return true;
    if(s == NULL || t == NULL) return false;
    if ((s -> val) != (t -> val)) return false;
    return isSame(s -> left, t ->left) && isSame(s -> right, t -> right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if(s == NULL) return false;
    if(isSame(s,t)) return true;
   	return isSubtree(s->left, t) || isSubtree(s -> right, t);
}