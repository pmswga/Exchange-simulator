#include "order.h"

void print_order(const struct order *o)
{
    printf("%d", o->id);
    printf(",");

    switch(o->side)
    {
    case BUY:
      printf("B");
      break;
    case SELL:
      printf("S");
      break;
    default:
      break;
    }
    printf(",");

    printf("%s", o->instrument);
    printf(",");

    printf("%d", o->qty);
    printf(",");

    printf("%.2f", o->price);
    printf("\n");
}
