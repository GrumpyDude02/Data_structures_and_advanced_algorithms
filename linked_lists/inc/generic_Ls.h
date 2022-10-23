#ifndef generic_Ls_h
#define generic_Ls_h
#include <stdlib.h>
#include <stdio.h>

typedef enum
{
    INT,
    FLOAT,
    CHAR
} data_type;

typedef struct generic_node
{
    data_type type;
    void *data;
    unsigned size;
    struct generic_node *next;

} generic_node;

generic_node *g_init(const void *data, size_t data_size, int eff_size, data_type type);
void g_push(generic_node *head, const void *data, size_t data_size, int eff_size, data_type);
void g_destroy(generic_node *head);
void print_glist(generic_node *head);

#endif