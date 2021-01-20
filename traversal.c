#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int val)
{
    struct node* Node = (struct node*) malloc(sizeof(struct node));
    Node->data = val;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);

}

void insert(struct node** root,int val)
{
   if(*root == NULL)
    *root = newNode(val);
    else if((*root)->data <= val)
        insert(&((*root)->right), val);
    else if((*root)->data > val)
        insert(&((*root)->left), val);

}

void preorder(struct node* root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
int maxDepth(struct node* node)
{
    if (node == NULL)
        return 0;
    else
    {

        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);


        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}

void inorder(struct node *root)
{
    if(root==NULL) return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if(root==NULL) return;

    postorder(root->left);

    postorder(root->right);
     printf("%d ",root->data);
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    struct node *root = NULL;

        for(int i=0;i<n;i++)
        insert(&root,a[i]);

        preorder(root);
        printf("\n");
        inorder(root);
         printf("\n");
        postorder(root);
       // printf("%d",maxDepth(root));


}
