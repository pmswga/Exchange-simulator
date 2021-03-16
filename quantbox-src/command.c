#include "command.h"

int is_correct_command(char *command_string)
{
    enum states {
        START = 1, STOP = 1, ERROR = 0
    };

    int state = START;
    
    if (strlen(command_string) > 0 && command_string != NULL) {
        char *token = strtok(command_string, ",");
        
        float number = 0.0;
        
        while (token != NULL) {
            
            switch (state) {
                case START:
                {
                    if (strcmp(token, "O") == 0 || strcmp(token, "C") == 0) {
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
                        state++;
                    } else {
                        state = ERROR;
                    }
                } break;
                case 4:
                {
                    if (strcmp(token, "Apple") == 0) {
                        state++;
                    } else {
                        state = ERROR;
                    }
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
    
    return state;
}

void print_command(const union command *c)
{


    printf("O");
    printf("C");
    printf("X");
    printf("T");
}
