#include "command.h"

int is_correct_open_command(const char *command_string)
{
    enum states {
        START = 1, STOP = 1, ERROR = 0
    };

    int state = START;
    char *command = (char*) malloc(sizeof (char) * strlen(command_string));
    strcpy(command, command_string);
    
    if (strlen(command_string) > 0 && command_string != NULL) {
        char *token = strtok(command, ",");
        
        float number = 0.0;
        
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

int is_correct_close_command(const char *command_string)
{
    enum states {
        START = 1, STOP = 1, ERROR = 0
    };

    int state = START;
    
    char *command = (char*) malloc(sizeof(char) * strlen(command_string));
    strcpy(command, command_string);
    
    if (strlen(command_string) > 0 && command_string != NULL) {
        char *token = strtok(command, ",");
        float number = 0.0;
        
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

struct command* get_command_from_string(char *command_string)
{
    struct command *c = (struct command*) malloc(sizeof (struct command));
    c->order = (struct order*) malloc(sizeof (struct order));
    
    if (!c || !c->order) {
        exit(1);
    }
    
    if (strlen(command_string) > 0 && command_string != NULL) {
        char *token = strtok(command_string, ",");
        int step = 0;
        int count = 0;
        float number = 0.0;
        
        while (token != NULL) {
            
            switch (step) {
                case 0:
                {
                    if (strcmp(token, "O") == 0) {
                        c->type = OPEN;
                    } else { 
                        c->type = CLOSE;
                    }
                    
                    step++;
                } break;
                case 1:
                {
                    number = atoi(token);
                    if (number > 0) {
                        c->order->id = number;
                    }
                    
                    step++;
                } break;
                case 2:
                {
                    if (strcmp(token, "B") == 0 || strcmp(token, "S") == 0) {
                        c->order->side = BUY;
                    } else { 
                        c->order->side = SELL;
                    }
                    
                    step++;
                } // fix it. While we don't know what is instument written in line
                case 3:
                {
                    c->order->instrument = (char*) malloc(sizeof (char) * 30);
                    if (!c->order->instrument) {
                        exit(1);
                    }
                    
                    strcpy(c->order->instrument, "Яблоки");
                    
                    step++;
                } break;
                case 4:
                {
                    count = atoi(token);
                    if (count > 0) {
                        c->order->qty = count;
                    }
                    
                    step++;
                } break;
                case 5:
                {
                    number = atof(token);
                    if (number > 0) {
                        c->order->price = number;
                    }
                    
                    step++;
                } break;
            }
            
            token = strtok(NULL, ",");
        }

        return c;
    }
    
    free(c->order);
    free(c);
    return 0;
}
