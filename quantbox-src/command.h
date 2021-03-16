#ifndef COMMAND_H
#define COMMAND_H

#include "order.h"
#include "trade.h"
#include "ctype.h"

//79 - Char of 'O'
//67 - Char of 'C'
enum command_type {
    OPEN     = 79, ///< Char of 'O'
    CLOSE    = 67, ///< Char of 'C'
    TRANSFER = 3,
    X        = 4
};

union command {
    enum command_type type;
    struct order order;
    struct trade trade;
};

int is_correct_command(char *command_string);
union command* get_command(const char *command_string);

void print_command(const union command *c);


#endif // COMMAND_H
