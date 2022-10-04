#include <stdio.h>
#include <stdlib.h>
#include "linked_Ls.h"

/*struct node_int
{
    int data;
    struct node_int *next;

} typedef node_int;

typedef struct node_int *node_p;

// useful functions
void insert(node_p *head, int index, int data)
{

    node_p temp = (node_p)malloc(sizeof(node_int));

    if (index <= 1 && *head != NULL)
    {
        temp->data = data;
        temp->next = *head;
        *head = temp;
    }
    else
    {
        temp = *head;
        for (int i = 1; i < index - 1; i++)
        {
            temp = temp->next;
        }
        node_p temp2 = (node_p)malloc(sizeof(node_int));
        node_p temp3 = (node_p)malloc(sizeof(node_int));
        temp3 = temp->next;
        temp->next = temp2;
        temp2->data = data;
        temp2->next = temp3;
    }
}

void delete__(node_p *head, int index)
{
    node_p temp = *head;
    if (index <= 1 && *head != NULL)
    {
        *head = temp->next;
        return;
    }
    else
    {
        for (int i = 0; i < index - 2; i++)
        {
            temp = temp->next;
            if (temp->next == NULL)
            {
                printf("no such node\n");
                return;
            }
        }
    }
    node_p temp2 = temp->next;
    temp->next = (temp2)->next;
    free(temp2);
}

void print_list(node_p head)
{
    node_p temp = (node_p)malloc(sizeof(node_int));
    temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//-----------------------------------------------------
*/
node_p insert_node_end(node_p head, int data)
{
    node_p temp = (node_p)malloc(sizeof(node_int));
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node_p new_node = (node_p)malloc(sizeof(node_int));
    new_node->data = data;
    new_node->next = NULL;
    temp->next = new_node;
    return new_node;
}

void insert_node_start(node_p *head, int data)
{
    node_p new_head = (node_p)malloc(sizeof(node_int));
    new_head->data = data;
    new_head->next = (*head);
    *head = new_head;
}

void delete_node(node_p node, node_p prev_node)
{
    prev_node->next = node->next;
    free(node);
}

void replace_head(node_p *head, int data)
{
    insert_node_start(head, data);
    delete__(head, 1);
}

int main()
{
    node_p head;
    head = (node_p)malloc(sizeof(node_int));

    head->data = 2;
    head->next = NULL;

    insert_node_start(&head, 1);
    node_p new_node = insert_node_end(head, 3);
    node_p new_node1 = insert_node_end(head, 4);
    print_list(head);
    insert(head, 2, 99);
    print_list(head);
    delete__(&head, 1);
    print_list(head);
    printf("\n");
    print_in_reverse(head);
    int x;
    scanf("%d", &x);
    return 0;
}