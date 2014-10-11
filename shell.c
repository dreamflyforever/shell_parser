/*
 * discription: The shell parser
 *
 * Author           time           
 * Shanjin Yang     2014.9.19
 *
 * GPL license
 *
 */

#include "shell.h"

/*The buff for input command*/
U8 buff_cmd[128];

U8 history[10][100];

SYMBOL sym_head;

void symbol_list_init(SYMBOL *sym)
{
    list_init(&sym->list);
}

void symbol_list_insert(SYMBOL *sym)
{
    list_insert(&sym_head.list, &sym->list);
}

void export(FUNC_PTR func, U8 *name)
{   
    /*the destination of token is just to malloc different memory object*/
    SYMBOL * token(func) = malloc(sizeof(SYMBOL));  
    token(func)->func = func;
    token(func)->name = name;
    symbol_list_insert(token(func));  
}

int parser(U8 *cmd)
{
    SYMBOL *sym_tmp;
    LIST *tmp = &sym_head.list;

    for (; !is_list_empty(tmp); tmp = tmp->next)
    { 
        sym_tmp = list_entry(tmp->next, SYMBOL, list);
        if (!strcmp(cmd, sym_tmp->name))
        {
            sym_tmp->func(NULL);
            return TURE;
        }
    }
    return FALSE;
}

int judge_key_up_or_down(U8 key)
{
    initscr();
    keypad(stdscr,true);
    
    while (key){
        
        switch (key){
        
            case DOWN_KEY:
                deleteln();
                //printw("%s",  history[i]);
                break;
        
            case UP_KEY:
                deleteln();
                //printw("%s", history[i]);
                break;
        
            case RIGHT_KEY:
                break;
        
            case LEFT_KEY: 
                break;
            
            default: 
                break;
        }
    }
    endwin();
    return 1; 
}
