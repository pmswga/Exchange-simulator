#ifndef EXECUTER_H
#define EXECUTER_H

#include "order_list.h"


void execute_order(struct order *initiator, struct order *requester)
{
    if (initiator->data->open_order.side == BUY) {
        requester->data->open_order.qty -= initiator->data->open_order.qty;
    } else if (initiator->data->open_order.side == SELL) {
        initiator->data->open_order.qty -= requester->data->open_order.qty;
    }
}


#endif // EXECUTER_H
