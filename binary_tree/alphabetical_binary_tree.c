#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    false,
    true
} bool;

int min(int x, int y)
{
    int min = x < y ? x : y;
    return min;
}

char *convert_lower_case(char *a)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] >= 65 && a[i] <= 90)
            a[i] = a[i] + 32;
    }
    return a;
}

bool compare_words(char *a, char *b)
{
    int i;
    int n = min(strlen(a), strlen(b));
    for (i = 0; i < n; i++)
    {
        if (a[i] >= 65 && a[i] <= 90)
            a[i] = a[i] + 32;
        if (b[i] >= 65 && b[i] <= 90)
            b[i] = b[i] + 32;
        if (a[i] > b[i])
            return true;
        else if (a[i] < b[i])
            return false;
    }
    if (i == n)
        return false;
    return true;
}

typedef struct node
{
    char *wordo;
    struct node *left;
    struct node *right;
} node;

void insert__(char *word, node *root)
{
    if (root == NULL)
        return;
    if (!(compare_words(word, root->wordo)))
    {
        if (root->left == NULL)
        {
            node *new_n = (node *)malloc(sizeof(node));
            new_n->left = NULL;
            new_n->right = NULL;
            new_n->wordo = word;
            root->left = new_n;
        }
        else
        {
            insert__(word, root->left);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            node *new_n = (node *)malloc(sizeof(node));
            new_n->left = NULL;
            new_n->right = NULL;
            new_n->wordo = word;
            root->right = new_n;
        }
        else
        {
            insert__(word, root->right);
        }
    }
}

void in_order_traversal(node *root)
{
    if (root != NULL)
    {
        in_order_traversal(root->left);
        printf("%s->", root->wordo);
        in_order_traversal(root->right);
    }
    return;
}

int main()
{
    node *root = (node *)malloc(sizeof(node));
    root->left = NULL;
    root->right = NULL;
    root->wordo = "ap";
    char c[] = "cucumbah";
    char g[] = "grape";
    char a[] = "Apple";
    char d[] = "ban";
    char e[] = "banana";
    char f[] = "bani";

    insert__(e, root);
    insert__(c, root);
    insert__(g, root);
    insert__(e, root);
    insert__(a, root);
    insert__(d, root);
    insert__(f, root);
    if (compare_words(d, e))
    {
        printf("hh");
    }
    else
    {
        printf("g");
    }
    in_order_traversal(root);
    return 0;
}
