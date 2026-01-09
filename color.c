#include "color.h"
#include <stdio.h>

char color_print(color c) 
{  
    const char* bg_colors[] = {BG_BLACK, BG_RED, BG_GREEN, BG_YELLOW, BG_BLUE, BG_MAGENTA, BG_CYAN, BG_WHITE};
        
    if (c < BLACK || c > WHITE) 
    {
        printf("Wrong input, exiting from the function.\n");
        return 1;
    }
    
    printf("%s ", bg_colors[c]); 
    printf("%s", RESET); 

    return ' ';
}
