#include "list.h"

void list_init(LIST *node)
{
    node->next = NULL;
}

void list_insert(LIST *head, LIST *node)
{
    node->next = head->next;
    head->next = node;
}

int is_list_empty(LIST *node)
{
    return node->next == NULL;
}
