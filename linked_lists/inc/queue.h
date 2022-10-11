#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include "generic_Ls.h"

typedef struct
{
    generic_node *head;
    generic_node *tail;
    data_type type;
    int num;
} queue;

int is_empty(queue *list);
queue *init_queue(data_type type);
void enqueue(queue **q, const void *data, int eff_size);
void q_insert_start(queue **q, const void *data, int eff_size);

#endif