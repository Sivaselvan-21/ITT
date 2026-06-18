//check bst
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int checkBST(struct Node *root,long min,long max)
{
    if(root == NULL)
        return 1;

    if(root->data <= min || root->data >= max)
        return 0;

    return checkBST(root->left,min,root->data) &&
           checkBST(root->right,root->data,max);
}

int isBST(struct Node *root)
{
    return checkBST(root,LONG_MIN,LONG_MAX);
}

int main()
{
    struct Node *root = createNode(2);
    root->left = createNode(1);
    root->right = createNode(3);

    if(isBST(root))
        printf("BST\n");
    else
        printf("Not BST\n");

    return 0;
}