/*
 * discription: example for The shell parser
 *
 * Author           time           
 * Shanjin Yang     2014.9.19
 *
 */

#include "shell.h"

void help(void *arg)
{
    SYMBOL *sym_tmp;
    LIST *tmp = &sym_head.list;

    for (; !is_list_empty(tmp); tmp = tmp->next)
    {
        sym_tmp = list_entry(tmp->next, SYMBOL, list);
        printf("symbol  --%s\n", sym_tmp->name);
    }
}

void version(void *arg)
{
    printf("No version, TMD\n");
}

void fuck(void *arg)
{
    printf("fuck fuck!!!\n");
}

int main()
{
    export(help, "help");
    export(version, "version");
    export(fuck, "fuck");

    /*the index of history for user input cmd*/ 
    U8 index = 0; 

    U8 i;

    printf("tmd-> ");

    while(TURE){

        /*catch input string*/
        for (i = 0, buff_cmd[i] = getchar(); buff_cmd[i] != '\n'; i++, buff_cmd[i] = getchar());
        
        /*input enter key will go to restart*/  
        if(buff_cmd[0] == '\n')
            goto restart;

        /*end of input string*/
        buff_cmd[i] = '\0';

        memcpy(history[index], buff_cmd, i);
        index ++;
        if (index == 10)
            index = 0;

        /*parser input string*/ 
        if ( !parser(buff_cmd) )
            printf("%s: command not found\n", buff_cmd);
  
        memset(buff_cmd, 0, 128); 
restart:   
        printf("\ntmd-> ");
    }
    return 0;
}
