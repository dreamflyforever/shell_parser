#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define token(abc) func_##abc

extern U8 buff_cmd[128];
typedef  void (*FUNC_PTR)(void *p_arg);

typedef struct SYMBOL{
    LIST list;
    FUNC_PTR  func;
    void *arg;
    char *name;
}SYMBOL;

extern SYMBOL sym_head;

void symbol_list_init();
void symbol_list_insert();
void symbol_list_delete();

void export(FUNC_PTR func, U8 *name);

int parser();

#endif
