#ifndef EXCHANGE_H
#define EXCHANGE_H

#include "order.h"
#include "command.h"

struct exchange {
    unsigned int count;
    struct command *commands;
};

void add_command(struct exchange *e, struct command *c);

void execute_current_command();
void destroy_exchange(struct exchange *e);

#endif // EXCHANGE_H
