#ifndef linked_Ls_h
#define linked_Ls_h

typedef struct node_int
{
    int data;
    struct node_int *next;
} node_int;

typedef node_int *node_p;

void insert(node_p head, int index, int data);
void delete__(node_p *head, int index);
void print_list(node_p head);
void reverse(node_p *HEAD);

#endif