//Binary Tree to Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *head = NULL;
struct Node *prev = NULL;

struct Node* createNode(int data)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void convert(struct Node *root)
{
    if(root == NULL)
        return;

    convert(root->left);

    if(prev == NULL)
        head = root;
    else
    {
        prev->right = root;
        root->left = prev;
    }

    prev = root;

    convert(root->right);
}

void printForward(struct Node *head)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);

        if(temp->right == NULL)
            break;

        temp = temp->right;
    }

    printf("\n");
}

void printBackward(struct Node *tail)
{
    while(tail != NULL)
    {
        printf("%d ", tail->data);
        tail = tail->left;
    }

    printf("\n");
}

int main()
{
    struct Node *root = createNode(1);
    root->left = createNode(3);
    root->right = createNode(2);

    convert(root);

    printf("DLL Forward:\n");
    printForward(head);

    struct Node *tail = head;

    while(tail->right != NULL)
        tail = tail->right;

    printf("DLL Backward:\n");
    printBackward(tail);

    return 0;
}