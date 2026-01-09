#ifndef GIF_H
#define GIF_H

#include "image.h"

// for deleting terminal content
#define TERMINAL_CLEAR "\033[2J"
#define TERMINAL_HOME "\033[H"

typedef struct 
{
    image frames[10];
} gif;

void load_gif(const char* base_filename, gif* g);
void print_gif(const gif* g);

#endif 
