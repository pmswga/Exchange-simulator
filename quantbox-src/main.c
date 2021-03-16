#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "order.h"
#include "trade.h"
#include "command.h"

int main(int argc, char **argv)
{
    char command[] = "T,1,B,Apple,10,250.12";
    
    int result = is_correct_command(command);

    printf("\n");
    printf("Result of check command: %d\n", result);
    
    return 0;
}
