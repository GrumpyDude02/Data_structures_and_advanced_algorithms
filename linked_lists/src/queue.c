#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int is_empty(queue *list)
{
    if (list->head == NULL && list->tail == NULL)
    {
        return 1;
    }
    return 0;
}

queue *init_queue(data_type type)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->type = type;
    q->head = NULL;
    q->tail = NULL;
    q->num = 0;
    return q;
}

void enqueue(queue **q, const void *data, int eff_size)
{

    generic_node *new_element = (generic_node *)malloc(sizeof(generic_node));
    switch ((*q)->type)
    {
    case (INT):
        new_element->type = INT;
        new_element->data = malloc(sizeof(int) * eff_size);
        memcpy(new_element->data, data, sizeof(int) * eff_size);
        for (int i = 0; i < eff_size; i++)
            *((int *)new_element->data + i) = *((int *)data + i);
        break;
    case (FLOAT):
        new_element->type = FLOAT;
        new_element->data = malloc(sizeof(float) * eff_size);
        memcpy(new_element->data, data, sizeof(float) * eff_size);
        break;
    case (CHAR):
        new_element->type = CHAR;
        new_element->data = malloc(sizeof(char) * eff_size);
        memcpy(new_element->data, data, sizeof(char) * eff_size);
    }
    if (is_empty(*q))
        (*q)->head = new_element;

    (*q)->tail = new_element;
    (*q)->tail->next = NULL;
    (*q)->num++;
}

void q_insert_start(queue **q, const void *data, int eff_size)
{
    generic_node *new_element = (generic_node *)malloc(sizeof(generic_node));
    switch ((*q)->type)
    {
    case (INT):
        new_element->type = INT;
        new_element->data = malloc(sizeof(int) * eff_size);
        new_element->next = NULL;
        memcpy(new_element->data, data, sizeof(int) * eff_size);
        break;
    case (FLOAT):
        new_element->type = FLOAT;
        new_element->data = malloc(sizeof(float) * eff_size);
        memcpy(new_element->data, data, sizeof(float) * eff_size);
        break;
    case (CHAR):
        new_element->type = CHAR;
        new_element->data = malloc(sizeof(char) * eff_size);
        memcpy(new_element->data, data, sizeof(char) * eff_size);
    }
    new_element->next = (*q)->head;
    (*q)->head = new_element;
    (*q)->num++;
    if (is_empty(*q))
        (*q)->tail = new_element;
}

void dequeue(queue **q)
{
    generic_node *temp = (*q)->head;
    (*q)->head = (*q)->head->next;
    free(temp->data);
    free(temp);
    (*q)->num--;
    if ((*q)->head == NULL)
    {
        (*q)->tail = NULL;
    }
}