//Check Whether All Leaves Are at Same Leve
#include <stdio.h>
#include <stdlib.h>

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

int leafLevel = -1;

int checkLeaves(struct Node *root, int level)
{
    if(root == NULL)
        return 1;

    if(root->left == NULL && root->right == NULL)
    {
        if(leafLevel == -1)
            leafLevel = level;

        return (leafLevel == level);
    }

    return checkLeaves(root->left, level + 1) &&
           checkLeaves(root->right, level + 1);
}

int main()
{
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    if(checkLeaves(root, 0))
        printf("All leaves are at same level\n");
    else
        printf("Leaves are at different levels\n");

    return 0;
}