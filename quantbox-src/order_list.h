#ifndef ORDER_LIST_H
#define ORDER_LIST_H

#include <stdlib.h>
#include <stdio.h>

#include "order.h"

struct order_list
{
    unsigned int size;
    struct order *head;
};

void add_order(struct order_list *lst, struct order *o)
{
    if (lst) {
        if (!lst->head) {
            lst->head = o;
            lst->head->id = lst->size+1;
        } else {
            struct order *sinker = lst->head;
            
            while (sinker->next) {
                sinker = sinker->next;
            }
            
            sinker->next = o;
            sinker->next->id = lst->size+1;
        }
        
        lst->size++;
    }
}

void remove_order(struct order_list *lst, unsigned int id)
{
    if (lst && lst->head) {
        struct order *sinker = NULL;
        
        if (lst->head->id == id) {
            sinker = lst->head;
            lst->head = lst->head->next;
            free(sinker->data);
            free(sinker);
        } else {
            struct order *previous = NULL;
            sinker = lst->head;
            
            while (sinker->id != id ) {
                previous = sinker;
                sinker = sinker->next;
            }
            
            previous->next = sinker->next;
            free(sinker->data);
            free(sinker);
        }
    }
}

void print_list(struct order_list *lst)
{
    if (lst && lst->head) {
        struct order *sinker = lst->head;
        
        while (sinker) {
            printf("[%d]| \n", sinker->id);
            
            sinker = sinker->next;
        }
    }
}

void destory_list(struct order_list *lst)
{
    if (lst) {
        if (lst->head) {
            struct order *sinker = lst->head;
            
            while (sinker) {
                lst->head = lst->head->next;
                
                if (sinker->data) {
                    free(sinker->data);
                }
                
                free(sinker);
                sinker = lst->head;
            }
        }
        
        free(lst);
    }
}

#endif // ORDER_LIST_H
