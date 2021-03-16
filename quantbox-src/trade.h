#ifndef TRADE_H
#define TRADE_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

struct trade {
    unsigned int id;
    enum exchange_operation side;
    unsigned int order_id;
    unsigned int sell_id;
    unsigned int qty;
    float price;
};

void print_trade(const struct trade *t);

#endif // TRADE_H
