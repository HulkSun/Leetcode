/*author:HULK
date:2017-04-13 20:43:23

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.*/

/**
 * Definition for a binary tree node.*/
#include <stdio.h>
#include <malloc.h>

  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 
void output(int* order, int orderSize)
{
	int i;
	for(i = 0 ; i < orderSize ; i++)
	{
		printf("%d ", order[i]);
	}
	printf("\n");

}

void cut(int* order, int begin, int end , int* result)
{
	int* new_result = (int*)realloc(result ,sizeof(int)*(end-begin));
	if(!new_result){
		int i,j;
		for(i = 0, j = begin ; j < end ; i++,j++)
		{
			new_result[i] = order[j];
		}	
		result = new_result;
	}
	else printf("memory alloc failed!\n");
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {

 	printf("preorder\n");
    output(preorder,preorderSize);
	printf("inorder\n");
    output(inorder, inorderSize);
 	printf("preorderSize %d\n", preorderSize);
    printf("inorderSize %d\n", inorderSize);
	if (preorderSize <= 0 )
	{
		printf("嗯~ o(*￣▽￣*)o\n");
		return NULL;
	}

	if (inorderSize <= 0 )
	{
		printf("嗯~ o(*￣▽￣*)o\n");
		return NULL;
	}

    int center;

    int leftPreorderSize;
    int rightPreorderSize;
    int leftInorderSize;
    int rightInorderSize;
    int* leftPreorder = (int*)malloc(sizeof(int));
    int* leftInorder = (int*)malloc(sizeof(int));
    int* rightInorder = (int*)malloc(sizeof(int));
    int* rightPreorder = (int*)malloc(sizeof(int));
    // int* leftPreorder = NULL;
    // int* leftInorder = NULL;
    // int* rightInorder = NULL;
    // int* rightPreorder = NULL;

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int rootVal = preorder[0];
    printf("当前根:%d\n", rootVal);

    root->val = rootVal;
    
    for(center = 0 ; center < inorderSize ; center++)
    {
    	if (inorder[center] == rootVal)break;
    }

    printf("center:%d\n", center);

    leftInorderSize = leftPreorderSize = center;
    rightInorderSize = rightPreorderSize = preorderSize - center -1;

    printf("leftPreorderSize %d\n", leftPreorderSize);
    printf("rightPreorderSize %d\n", rightPreorderSize);
    printf("leftInorderSize %d\n", leftInorderSize);
    printf("rightInorderSize %d\n", rightInorderSize);


    cut(preorder, 1, center+1, leftPreorder);
    cut(preorder, center+1, preorderSize, rightPreorder);
    cut(inorder, 0, center, leftInorder);
    cut(inorder, center+1, inorderSize, rightInorder);

   
    printf("leftInorder\n");
    output(leftInorder, leftInorderSize);
    printf("rightInorder\n");
    output(rightInorder, rightInorderSize);
    printf("leftPreorder\n");
    output(leftPreorder, leftPreorderSize);
    printf("rightPreorder\n");
    output(rightPreorder, rightPreorderSize);
    printf("========\n");

    printf("start left:\n");
	root->left = buildTree(leftPreorder,leftPreorderSize, leftInorder,leftInorderSize);
	printf("start right:\n");
	root->right = buildTree(rightPreorder, rightPreorderSize ,rightInorder,rightInorderSize);

    // free(leftInorder);
    // free(leftPreorder);
    // free(rightInorder);
    // free(rightPreorder);

    return root;

}

int main(int argc, char const *argv[])
{

	int control = 1;
	if(control){
		int preorder[200] = {-77,24,-74,84,93,28,83,6,95,58,59,66,22,-3,-66,-68,-22,3,-80,-79,-85,17,32,9,-88,-99,14,-60,13,-93,-63,91,82,21,26,-11,-32,-16,-100,-94,-31,-62,-89,49,-9,-8,87,-33,-81,80,0,69,-7,52,67,-5,-65,31,-30,37,-57,27,23,38,-28,7,-82,-42,11,-55,-36,-58,-24,89,56,73,41,18,-87,-70,4,-64,20,-52,-39,79,19,30,65,25,-71,-76,-1,62,-69,98,39,-25,-73,70,88,-17,-20,-75,55,34,57,81,-10,94,48,-35,5,-23,-44,40,-51,-61,-13,-86,63,71,-97,45,43,51,75,33,-34,92,47,-78,85,-26,97,-29,-92,-83,-59,74,96,68,77,16,-4,10,60,64,-21,-2,1,-91,86,46,76,-37,-19,-96,36,-98,29,-72,61,50,15,-95,-40,-43,-53,90,-15,-48,-27,-90,-54,72,-50,-49,-18,78,54,35,-38,99,44,-67,53,-12,-41,2,8,-14,-84,-56,-6,12,-45,42,-47,-46};
		int inorder[200] = {93,28,84,83,-74,59,58,66,-66,-3,-79,-80,3,-22,-68,22,-85,-99,14,-88,9,32,17,-60,95,-93,82,21,91,-63,26,13,-16,-32,-11,-100,6,-62,49,-89,-31,87,-8,69,0,80,-7,-81,-65,-5,67,-30,31,52,-33,37,-57,-9,7,-28,-42,-82,38,-55,11,23,-36,27,56,89,73,-24,41,-58,-70,-87,20,-64,-52,4,18,-94,19,30,-76,-1,-71,62,-69,25,-73,-25,70,39,88,98,-20,-17,65,55,-75,79,34,-39,48,94,-23,5,-44,-35,40,-10,-61,-51,-13,81,63,-97,71,-86,57,45,24,-34,85,97,-26,-78,-83,-92,74,-59,96,-29,68,47,77,92,10,-4,16,60,33,-21,1,86,76,46,-37,-91,-2,64,75,51,-19,-96,43,-98,29,61,-72,50,36,-95,-40,-43,15,90,-15,-53,-77,-54,-90,-49,-50,72,-27,35,54,-38,78,-67,44,53,99,-41,-12,-18,8,2,-48,-56,-84,-14,-45,12,42,-6,-46,-47};
		buildTree(preorder,200,inorder,200);
	}
	else
	{
		int preorder[10] = {1,2,4,7,8,5,3,6,9,10};
		int inorder[10] = {7,4,8,2,5,1,3,9,6,10};
		buildTree(preorder,10,inorder,10);
	}
	
	// int preorder[9] = {1,2,4,7,8,5,3,6,9};
	// int inorder[9] = {7,4,8,2,5,1,3,9,6};
	// buildTree(preorder,9,inorder,9);
	// int preorder[1] = {1};
	// int inorder[1] = {1};
	// buildTree(preorder,1,inorder,1);
	// int preorder[2] = {1,2};
	// int inorder[2] = {1,2};
	// buildTree(preorder,2,inorder,2);
	// int preorder[3] = {1,2,3};
	// int inorder[3] = {2,1,3};
	// buildTree(preorder,3,inorder,3);

	return 0;
}