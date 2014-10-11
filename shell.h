#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#include <curses.h>

#define DOWN_KEY  2
#define UP_KEY    3
#define LEFT_KEY  4
#define RIGHT_KEY 5

#define token(abc) func_##abc

extern U8 buff_cmd[128];

extern U8 history[10][100];

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

int parser(U8 *cmd);

int judge_key_up_or_down(U8 key);

#endif
