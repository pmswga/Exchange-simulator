#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "order_list.h"


int main(int argc, char **argv)
{
    struct order_list *lst = malloc(sizeof (struct order_list));
    lst->head = NULL;
    lst->size = 0;
    
    if (argc == 3) {
        FILE *fp = fopen(argv[1], "r");
        char *s = (char*) malloc(sizeof (char) * 255);
        
        if (!fp) {
            exit(1);
        }
        
        while (!feof(fp)) {
            fgets(s, 255, fp);
            
            if (is_correct_open_order(s) == 1) {
                add_order(lst, get_open_order_from_string(s));
            } else if (is_correct_close_order(s) == 1) {
                add_order(lst, get_close_order_from_string(s));
            }
            
        }
        
        free(s);
        fclose(fp);
    }
    
    
    
    print_list(lst);
    
    
    // Execute orders
    
    
    
    
    
    
    destory_list(lst);
    
    return 0;
}
