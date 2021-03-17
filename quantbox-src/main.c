#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exchange.h"
#include "order.h"
#include "trade.h"
#include "command.h"
#include "types.h"


int main(int argc, char **argv)
{
    struct exchange e = {0, NULL};
    
    if (argc == 2) {
        
    } else if (argc == 3) {
        FILE *fp = fopen(argv[1], "r");
        char *s = (char*) malloc(sizeof (char) * 255);
        
        if (fp == NULL) {
            exit(1);
        }
        
        while (!feof(fp))
        {
            fgets(s, 255, fp);
            
            if (is_correct_open_command(s) == 1) {
                add_command(&e, get_command_from_string(s));
            } else if (is_correct_close_command(s) == 1) {
                add_command(&e, get_command_from_string(s));
            }
            
        }
        
        free(s);
        fclose(fp);
    }
    
    destroy_exchange(&e);
    
    return 0;
}


