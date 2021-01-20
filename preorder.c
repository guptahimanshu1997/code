#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


struct BinaryTreeNode{
int data;
struct BinaryTreeNode *left;
struct BinaryTreeNode *right;
};


struct BinaryTreeNode* buildTreeHelper(int *postorder, int postStart, int postEnd, int *inorder, int inStart, int inEnd) {
if (postStart > postEnd || inStart > inEnd) return NULL;

int rootVal = postorder[postEnd];

struct BinaryTreeNode*  root = (struct BinaryTreeNode*) malloc (sizeof(struct BinaryTreeNode));
root->data = rootVal;

int k = 0;
for (int i = inStart; i <= inEnd; i++) {
if (rootVal == inorder[i]) {
k = i;
break;
}
}
root->left = buildTreeHelper(postorder, postStart, postStart + k - inStart - 1, inorder, inStart, k - 1);
root->right = buildTreeHelper(postorder, postStart + k - inStart, postEnd - 1, inorder, k + 1, inEnd);
return root;
}

void preorder( struct BinaryTreeNode  *root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    scanf("%d",&n);
    int inorder[n];
    int postorder[n];
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&inorder[i]);

    for(i=0;i<n;i++)
        scanf("%d",&postorder[i]);

   struct BinaryTreeNode *pre  =   buildTreeHelper(postorder,0,n-1,inorder,0,n-1);
     preorder(pre);
}



