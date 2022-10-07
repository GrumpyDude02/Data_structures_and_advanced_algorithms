#ifndef generic_Ls_h
#define generic_Ls_h
#include <stdlib.h>
#include <stdio.h>

typedef struct generic_node
{
    void *data;
    struct generic_node *next;
} generic_node;

generic_node *g_init(const void *val, size_t data_size, int eff_size);
void g_push(generic_node *head, const void *data, size_t, int eff_size);
void g_destroy(generic_node *head);
void print_glist(generic_node *head, void (*print_type)(void *));

#endif