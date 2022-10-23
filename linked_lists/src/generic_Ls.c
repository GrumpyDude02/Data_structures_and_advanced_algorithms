#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic_Ls.h"

generic_node *g_init(const void *val, size_t size, int eff_size, data_type type)
{
    generic_node *head = (generic_node *)malloc(sizeof(generic_node));
    head->data = malloc(size * eff_size);
    head->next = NULL;
    head->type = type;
    head->size = eff_size;
    memcpy(head->data, val, size * eff_size);
    return head;
}

void g_push(generic_node *head, const void *data, size_t data_size, int eff_size, data_type type)
{
    generic_node *temp = head;
    if (head == NULL)
    {
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    generic_node *new_node = (generic_node *)malloc(sizeof(generic_node));
    temp->next = new_node;
    new_node->next = NULL;
    new_node->data = malloc(data_size * eff_size);
    new_node->type = type;
    new_node->size = eff_size;
    memcpy(new_node->data, data, data_size * eff_size);
}

void g_destroy(generic_node *head)
{
    generic_node *next;
    while (head != NULL)
    {
        next = head->next;
        free(head->data);
        free(head);
        head = next;
    }
}

void print_glist(generic_node *head)
{
    while (head != NULL)
    {
        switch (head->type)
        {
        case (INT):
            for (int i = 0; i < head->size; i++)
                printf("%d", *((int *)head->data + i));
            break;

        case (FLOAT):
            for (int i = 0; i < head->size; i++)
                printf("%f", *((float *)head->data + i));
            break;
        case (CHAR):
            printf("%s", (char *)head->data);
            break;
        }
        printf("->");
        head = head->next;
    }
    printf("NULL\n");
}
