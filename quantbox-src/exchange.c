#include "exchange.h"

void add_command(struct exchange *e, struct command *c)
{
    if (e) {        
        if (e->commands == NULL) {
            e->commands = (struct command*) malloc(sizeof(struct command) * e->count);
        } else {
            e->commands = (struct command*) realloc(e->commands, sizeof (struct command) * (e->count + 1));
        
            
            e->count++;
            e->commands[e->count-1] = *c;
        }
    } else {
        exit(1);
    }
}


void destroy_exchange(struct exchange *e)
{
    if (e) {
        free(e->commands);
    }
}
