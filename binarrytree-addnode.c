#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int key;
    struct node *left;
    struct node *right;
};
 

struct node *getNode(int val)
{
    struct node *newNode;
 
    newNode = malloc(sizeof(struct node));
 
    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;
 
    return newNode;
}
 

struct node *insertNode(struct node *root, int val)
{
     if(root == NULL)
         return getNode(val);
 
     if(root->key < val)
         root->right = insertNode(root->right,val);
 
     if(root->key > val)
         root->left = insertNode(root->left,val);
 
     return root;
}
 

void inorder(struct node *root)
{
    if(root == NULL)
        return;
 
    
    inorder(root->left);
 

    printf("%d ",root->key);
 
    inorder(root->right);
}
 
int main()
{
   struct node *root = NULL;
 
   root = insertNode(root,100);
   root = insertNode(root, 50);
   root = insertNode(root, 200);
   root = insertNode(root, 10);
   root = insertNode(root, 60);
   root = insertNode(root, 150);
   root = insertNode(root, 300);
 
 
   inorder(root);
   printf("\n");
   return 0;
}
 
