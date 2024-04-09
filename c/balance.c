#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node * right;
    int balancefactor;
    
}node;

node *createnode(int data)
{
    node * newnode=(node*)malloc(sizeof( node));
    if(newnode==NULL)
    {
        printf("Memory allocation failed");
    }
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->balancefactor=0;
    return newnode;
}

int height(node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    else{
        int leftheight= height(node->left);
        int rightheight=height(node->right);
        return (leftheight>rightheight)?(leftheight+1):(rightheight+1);
    }

}
 void calculatebalancefactor(node *node)
{
    if(node!=NULL)
    {
        node->balancefactor=height(node->left)-height(node->right);
        calculatebalancefactor(node->left);
        calculatebalancefactor(node->right);
    }
}

node *insert(node * root,int data)
{
    if(root==NULL)
    {
        return createnode(data);
    }
    if(data < root->data)
    {
        root->left= insert (root->left,data);
    }
    else if(data > root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}

void inordertraversal(node * root)
{
    if(root!=NULL)
    {
        inordertraversal(root->left);
        printf("\n node %d \n,\nbalancefactor :%d\n",root->data,root->balancefactor);
        inordertraversal(root->right);
    }
}

int main() {
    node *root = NULL;

    // Insert nodes into the binary search tree
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 7);
    insert(root, 15);
    insert(root, 25);

    // Calculate balance factor for each node
    calculatebalancefactor(root);

    // Print nodes and their balance factors
    printf("In-order traversal of the binary search tree:\n");
    inordertraversal(root);

    return 0;
}