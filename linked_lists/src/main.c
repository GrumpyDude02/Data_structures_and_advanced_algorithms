#include <stdio.h>
#include <stdlib.h>
#include "linked_Ls.h"
#include "generic_Ls.h"

void print_str(void *val)
{
    printf("%s", (char *)val);
}

void print_int(void *val)
{
    printf("%d", *(int *)val);
}

void print_float(void *val)
{
    printf("%f", *(float *)val);
}

int main()
{
    /*-------------integer linked list---------------*/
    node_p head;
    head = (node_p)malloc(sizeof(node_int));
    head->data = 2;
    head->next = NULL;
    print_list(head);
    insert(head, 2, 99);
    print_list(head);
    delete__(&head, 1);
    print_list(head);
    /*-------------generic linked list---------*/
    char p[] = "test";
    generic_node *head1 = g_init(p, sizeof(int), sizeof(p) / sizeof(char));
    g_push(head1, "Hello_World", sizeof(char), 12);
    print_glist(head1, print_str);
    g_destroy(head1);
    int a = 5;
    generic_node *list = g_init(&a, sizeof(int), 1);
    g_push(list, &a, sizeof(int), 1);
    print_glist(list, print_int);
    return 0;
}