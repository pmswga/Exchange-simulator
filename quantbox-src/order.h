#ifndef ORDER_H
#define ORDER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"

struct order {
  unsigned int id;
  enum exchange_operation side;
  char *instrument;
  unsigned int qty;
  float price;
};

void print_order(const struct order *er);


#endif // ORDER_H
