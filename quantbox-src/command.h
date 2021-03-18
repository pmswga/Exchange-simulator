#ifndef COMMAND_H
#define COMMAND_H

#include "order.h"
#include "trade.h"
#include "ctype.h"
#include <string.h>

enum command_type {
    OPEN     = 1,
    CLOSE    = 2,
    TRANSFER = 3,
    X        = 4
};

struct command {
    enum command_type type;
    struct order *order;
};

int is_correct_open_command(const char *command_string);
int is_correct_close_command(const char *command_string);

struct command* get_command_from_string(char *command_string);

void print_command(struct command *c);


#endif // COMMAND_H
