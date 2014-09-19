#ifndef __LIST_H__
#define __LIST_h__

#define U8   unsigned char
#define U32  unsigned int
#define NULL (void *)0

enum BOOL{
    FALSE = 0,
    TURE  = 1,
};

typedef struct LIST{
   struct LIST *next;
}LIST;

#define list_entry(node, type, member)    ((type *)((U8 *)(node) - (U32)(&((type *)0)->member))) 

void list_init(LIST *node);

void list_insert(LIST *head, LIST *node);

int is_list_empty(LIST *node);

#endif
