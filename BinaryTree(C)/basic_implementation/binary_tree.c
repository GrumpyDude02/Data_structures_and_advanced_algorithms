#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b)
{
    int maximum = a >= b ? a : b;
    return maximum;
}

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef Node node;

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
            insert_node(val, HEAD->left);
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
            insert_node(val, HEAD->right);
        }
    }
}

bool search(node *HEAD, int val)
{
    if (HEAD == NULL)
    {
        printf("%d not found\n", val);
        return false;
    }
    if (HEAD->data == val)
    {
        printf("%d found\n", val);
        return true;
    }
    if (HEAD->data < val)
    {
        return search(HEAD->right, val);
    }
    if (HEAD->data > val)
    {
        return search(HEAD->left, val);
    }
    printf("%d not found\n", val);
    return false;
}

Node *trouverNoeud(Node *root, void *objet, int (*comparer)(void *, void *))
{
    if (!root)
        return NULL;
    if (comparer((void *)root, objet) == 0)
        return root;
    Node *temp;
    if (temp = trouverNoeud((void *)root->left, objet, comparer))
        return temp;
    if (temp = trouverNoeud((void *)root->right, objet, comparer))
        return temp;
    return NULL;
}

void in_order_traversal(node *HEAD)
{
    if (HEAD != NULL)
    {
        in_order_traversal(HEAD->left);
        printf("%d\t", HEAD->data);
        in_order_traversal(HEAD->right);
    }
    return;
}

void pre_order_traversal(node *HEAD)
{
    if (HEAD != NULL)
    {
        printf("%d\t", HEAD->data);
        in_order_traversal(HEAD->left);
        in_order_traversal(HEAD->right);
    }
    return;
}

void post_order_traversal(node *HEAD)
{
    if (HEAD != NULL)
    {
        in_order_traversal(HEAD->left);
        in_order_traversal(HEAD->right);
        printf("%d\t", HEAD->data);
    }
    return;
}

int tree_height(node *root)
{
    if (root != NULL)
    {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        return (max(left_height, right_height) + 1);
    }
    return 0;
}

void free_tree(node *root)
{
    if (root != NULL)
    {
        free_tree(root->left);
        free_tree(root->right);
    }
    free(root);
    return;
}

int is_balanced(node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    if (abs(right_height - left_height) <= 1 && is_balanced(root->left) && is_balanced(root->right))
    {
        return 1;
    }
    return 0;
}

int main()
{
    head = (node *)malloc(sizeof(node));
    head->data = 3;
    head->left = NULL;
    head->right = NULL;

    insert_node(2, head);
    insert_node(1, head);
    insert_node(0, head);
    insert_node(4, head);
    in_order_traversal(head);
    printf("\n");
    pre_order_traversal(head);
    printf("\n");
    post_order_traversal(head);
    printf("\n%d\n", tree_height(head));
    if (is_balanced(head))
        printf("balanced");
    else
        printf("not balanced");
    free_tree(head);
}