#include "gif.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

// load from file
void load_gif(const char* base_filename, gif* g) 
{
    char filename[50];

    for (int i = 0; i < 10; i++) 
    {
        snprintf(filename, sizeof(filename), "files/%s.bg%d", base_filename, i);
        FILE* file = fopen(filename, "r");
        if (!file) 
        {
            printf("Can't open the file. %s.\n", filename);
            exit(1);
        }

        // dimensions in
        fscanf(file, "%d", &g->frames[i].width);
        fscanf(file, "%d", &g->frames[i].height);

        // check dimensions
        if (g->frames[i].width > MAX_SIZE || g->frames[i].height > MAX_SIZE) {
            printf("Invalid dimensions %s.\n", filename);
            fclose(file);
            exit(1);
        }

        // read pixels
        for (int j = 0; j < g->frames[i].height; j++) 
        {
            for (int k = 0; k < g->frames[i].width; k++) 
            {
                int color_value;
                fscanf(file, "%d", &color_value);

                // color check
                if (color_value < BLACK || color_value > WHITE) 
                {
                    color_value = BLACK;
                }
                g->frames[i].pixels[j][k] = (color)color_value;
            }
        }

        fclose(file);
    }
}

// print gif to console
void print_gif(const gif* g) 
{
    for (int i = 0; i < 10; i++) 
    {
        // clear terminal
        printf("%s%s", TERMINAL_CLEAR, TERMINAL_HOME);

        // print frame
        image_print(&g->frames[i]);
        
        usleep(200000);
    }
}

