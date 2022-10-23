#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>

typedef enum
{
    INT,
    FLOAT,
    CHAR
} data_type1;

typedef struct generic_n
{
    data_type1 type;
    void *data;
    struct generic_n *next;

} generic_n;

typedef struct
{
    generic_n *head;
    generic_n *tail;
    data_type1 type;
    int num;
} queue;

int is_empty(queue *list);
queue *init_queue(data_type1 type);
void enqueue(queue **q, const void *data, int eff_size);
void q_insert_start(queue **q, const void *data, int eff_size);

#endif