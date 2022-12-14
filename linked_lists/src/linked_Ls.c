#include <stdio.h>
#include <stdlib.h>
#include "linked_Ls.h"

void insert(node_p head, int index, int data)
{

    node_p temp;

    if (index <= 1 && head != NULL)
    {
        temp = (node_p)malloc(sizeof(node_int));
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    else
    {
        temp = head;
        for (int i = 1; i < index - 1; i++)
        {
            temp = temp->next;
        }
        node_p temp2 = (node_p)malloc(sizeof(node_int));
        node_p temp3;
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
        free(temp);
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
    printf("NULL\n");
}

void reverse(node_p *HEAD)
{
    node_p prev = NULL;
    node_p temp = (*HEAD);
    node_p temp1;
    while (temp != NULL)
    {
        temp1 = temp->next;
        temp->next = prev;
        prev = temp;
        temp = temp1;
    }
    *HEAD = prev;
}

void print_in_reverse(node_p HEAD)
{
    node_p temp = HEAD;
    if (temp != NULL)
    {
        print_in_reverse(temp->next);
        printf("<-%d", temp->data);
    }
    else
    {
        printf("NULL");
        return;
    }
}
