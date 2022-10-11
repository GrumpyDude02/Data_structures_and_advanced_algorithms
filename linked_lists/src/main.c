#include <stdio.h>
#include <stdlib.h>
#include "linked_Ls.h"
#include "generic_Ls.h"
#include "queue.h"

static void print_str(void *val)
{
    printf("%s", (char *)val);
}

static void print_int(void *val)
{
    printf("%d", *(int *)val);
}

static void print_float(void *val)
{
    printf("%f", *(float *)val);
}
int main()
{
    /*-------------integer linked list test---------------*/
    node_p head;
    head = (node_p)malloc(sizeof(node_int));
    head->data = 2;
    head->next = NULL;
    print_list(head);
    insert(head, 2, 99);
    print_list(head);
    delete__(&head, 1);
    print_list(head);
    /*-------------generic linked list test---------*/
    char p[] = "test";
    generic_node *head1 = g_init(p, sizeof(int), sizeof(p) / sizeof(char), CHAR);
    g_push(head1, "Hello_World", sizeof(char), 12, CHAR);
    print_glist(head1);
    g_destroy(head1);
    int a = 5;
    generic_node *list = g_init(&a, sizeof(int), 1, INT);
    g_push(list, &a, sizeof(int), 1, INT);
    print_glist(list);
    printf("\n");
    /*-----------queue test---------------*/
    queue *q = init_queue(INT);
    enqueue(&q, &a, 1);
    printf("%d", *((int *)q->tail->data));
    return 0;
}