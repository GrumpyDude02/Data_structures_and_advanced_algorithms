#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *head;

void insert_node(int val, node *HEAD)
{
    if (val <= (HEAD)->data)
    {
        if ((HEAD)->left == NULL)
        {
            node *new_node = (node *)malloc(sizeof(node));
            new_node->data = val;
            new_node->left = NULL;
            new_node->right = NULL;
            (HEAD)->left = new_node;
        }
        else
        {
            node *new_n = (node *)malloc(sizeof(node));
            new_n = HEAD->left;
            new_n->left = NULL;
            new_n->right = NULL;
            insert_node(val, new_n);
        }
    }
    else
    {
        if ((HEAD)->right == NULL)
        {
            node *new_node = (node *)malloc(sizeof(node));
            new_node->data = val;
            new_node->left = NULL;
            new_node->right = NULL;
            (HEAD)->right = new_node;
        }
        else
        {
            node *new_node = (node *)malloc(sizeof(node));
            new_node = HEAD->right;
            new_node->left = NULL;
            new_node->right = NULL;
            insert_node(val, new_node);
        }
    }
}

int main()
{
    head = (node *)malloc(sizeof(node));
    head->data = 1;
    head->left = NULL;
    head->right = NULL;

    insert_node(2, head);
    insert_node(2, head);
    insert_node(0, head);
    insert_node(-1, head);

    printf("%d\n", head->data);
    node *temp = (node *)malloc(sizeof(node));
    temp = head->right;
    printf("%d\n", temp->data);
    return 0;
}