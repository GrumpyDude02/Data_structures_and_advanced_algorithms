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
    char *temp1 = (char *)malloc(sizeof(char) * strlen(a));
    char *temp2 = (char *)malloc(sizeof(char) * strlen(b));
    strcpy(temp1, a);
    strcpy(temp2, b);
    for (i = 0; i < n; i++)
    {
        if (temp1[i] >= 65 && temp1[i] <= 90)
            temp1[i] = temp1[i] + 32;
        if (temp2[i] >= 65 && temp2[i] <= 90)
            temp2[i] = temp2[i] + 32;
        if (temp1[i] > temp2[i])
        {
            free(temp1);
            free(temp2);
            return true;
        }
        if (temp1[i] < temp2[i])
        {
            free(temp1);
            free(temp2);
            return false;
        }
    }
    if (strlen(a) <= strlen(b))
    {
        free(temp1);
        free(temp2);
        return false;
    }
    free(temp1);
    free(temp2);
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
#ifdef __STDC_VERSION__
    printf("__STDC_VERSION__ = %ld \n", __STDC_VERSION__);
#endif

#ifdef __STRICT_AINSI__
    puts("__STRICT_AINSI__");
#endif

    node *root = (node *)malloc(sizeof(node));
    root->left = NULL;
    root->right = NULL;
    root->wordo = "ap";
    insert__("b", root);
    insert__("Apple", root);
    insert__("ba", root);
    insert__("bc", root);
    insert__("Hello", root);
    insert__("bd", root);
    insert__("ad", root);

    in_order_traversal(root);
    return 0;
}
