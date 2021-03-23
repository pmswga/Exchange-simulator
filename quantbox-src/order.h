#ifndef ORDER_H
#define ORDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum order_type {
    OPEN,
    CLOSE,
    TRANSFER,
    X
};

enum exchange_type {
    BUY,
    SELL
};

typedef struct {
    unsigned int oid;
    enum exchange_type side;
    char instrument[255];
    unsigned int qty;
    double price;
} open_order;

typedef struct {
    unsigned int cid;
} close_order;

typedef union {
    open_order open_order;
    close_order close_order;
} order_data;

struct order
{
    unsigned int id;
    enum order_type type;
    order_data *data;

    struct order *next;
};

struct order *get_open_order_from_string(char *order_string)
{
    if (strlen(order_string) > 0 && order_string != NULL) {
        struct order* o = malloc(sizeof (struct order));
        o->data = malloc(sizeof (order_data));
        o->next = NULL;
        
        char *token = strtok(order_string, ",");
        double number = 0.0;
        int state = 0;
        
        while (token != NULL) {
            switch (state) {
                case 0:
                {
                    if (strcmp(token, "O") == 0) {
                        o->type = OPEN;
                    }
                    
                    state++;
                } break;
                case 1:
                {
                    number = atof(token);
                    if (number > 0) {
                        o->data->open_order.oid = (unsigned long) number;
                    }
                    
                    state++;
                } break;
                case 2:
                {
                    if (strcmp(token, "B") == 0) {
                        o->data->open_order.side = BUY;
                    } else if (strcmp(token, "S") == 0) {
                        o->data->open_order.side = SELL;
                    }
                    
                    state++;
                } break;
                case 3:
                {
                    number = atof(token);
                    if (number > 0) {
                        o->data->open_order.qty = (unsigned int) number;
                    }
                    
                    state++;
                } //while we don't know what instrument written in line
                case 4:
                {
                    strcpy(o->data->open_order.instrument, "Яблоки");
                    
                    state++;
                } break;
                case 5:
                {
                    number = atof(token);
                    if (number > 0) {
                        o->data->open_order.price = number;
                    }
                    
                    state++;
                } break;
            }
            
            token = strtok(NULL, ",");
        }
        
        return o;
    }
    
    return 0;
}

struct order *get_close_order_from_string(char *order_string)
{
    if (strlen(order_string) > 0 && order_string != NULL) {
        struct order* o = malloc(sizeof (struct order));
        o->data = malloc(sizeof (order_data));
        o->next = NULL;
        
        char *token = strtok(order_string, ",");
        double number = 0.0;
        int state = 0;
        
        while (token != NULL) {
            switch (state) {
                case 0:
                {
                    if (strcmp(token, "C") == 0) {
                        o->type = CLOSE;
                    }
                    
                    state++;
                } break;
                case 1:
                {
                    number = atof(token);
                    if (number > 0) {
                        o->data->close_order.cid = number;
                    }
                    
                    state++;
                } break;
            }
            
            token = strtok(NULL, ",");
        }
        
        return o;
    }
    
    return 0;
}



int is_correct_open_order(const char *command_string)
{
    enum states {
        START = 1, STOP = 1, ERROR = 0
    };

    int state = START;
    char *command = (char*) malloc(sizeof (char) * strlen(command_string));
    strcpy(command, command_string);
    
    if (strlen(command_string) > 0 && command_string != NULL) {
        char *token = strtok(command, ",");
        double number = 0.0;
        
        while (token != NULL) {
            switch (state) {
                case START:
                {
                    if (strcmp(token, "O") == 0) {
                        state++;
                    } else {
                        state = ERROR;
                    }
                } break;
                case 2:
                {
                    number = atof(token);
                    if (number > 0) {
                        state++;
                    } else {
                        state = ERROR;
                    }
                } break;
                case 3:
                {
                    if (strcmp(token, "B") == 0 || strcmp(token, "S") == 0) {
                        state = 5; // fix it
                    } else {
                        state = ERROR;
                    }
                } break;
                case 4:
                {
                    /*
                    if (strcmp(token, "Apple") == 0) {
                        state++;
                    } else {
                        state = ERROR;
                    }
                    */
                } break;
                case 5:
                {
                    number = atof(token);
                    if (number > 0) {
                        state++;
                    } else {
                        state = ERROR;
                    }
                } break;
                case 6:
                {
                    number = atof(token);
                    if (number > 0) {
                        state = STOP;
                    } else {
                        state = ERROR;
                    }
                } break;
            }
            
            token = strtok(NULL, ",");
        }
    }
    
    free(command);
    
    return state;
}

int is_correct_close_order(const char *command_string)
{
    enum states {
        START = 1, STOP = 1, ERROR = 0
    };

    int state = START;
    
    char *command = (char*) malloc(sizeof(char) * strlen(command_string));
    strcpy(command, command_string);
    
    if (strlen(command_string) > 0 && command_string != NULL) {
        char *token = strtok(command, ",");
        double number = 0.0;
        
        while (token != NULL) {
            switch (state) {
                case START:
                {
                    if (strcmp(token, "C") == 0) {
                        state++;
                    } else {
                        state = ERROR;
                    }
                } break;
                case 2:
                {
                    number = atof(token);
                    if (number > 0) {
                        state = STOP;
                    } else {
                        state = ERROR;
                    }
                } break;
            }
            
            
            token = strtok(NULL, ",");
        }
    }
    
    return state;
}


#endif // ORDER_H
