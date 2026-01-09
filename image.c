#include "image.h"
#include <stdio.h>
#include <stdlib.h>

void load_image(image* img) 
{
    printf("Width (1-%d): ", MAX_SIZE);
    scanf("%d", &img->width);

    printf("Height (1-%d): ", MAX_SIZE);
    scanf("%d", &img->height);

    // validation
    if (img->width > MAX_SIZE || img->height > MAX_SIZE || img->width <= 0 || img->height <= 0) 
    {
        printf("Invalid data. The program exiting.\n");
        exit(1);
    }

    printf("Matrix:\n");
    for (int i = 0; i < img->height; i++) 
    {
        for (int j = 0; j < img->width; j++) 
        {
            int color_value;
            scanf("%d", &color_value);

            // ellenőrzés
            if (color_value < BLACK || color_value > WHITE) 
            {
                printf("Wrong color input (%d, %d). Color set to black.\n", i, j);
                color_value = BLACK;
            }

            img->pixels[i][j] = (color)color_value;
        }
    }
}

void image_print(const image* img) 
{
    for (int i = 0; i < img->height; i++) 
    {
        for (int j = 0; j < img->width; j++) 
        {
            color_print(img->pixels[i][j]); 
        }
        printf("\n");
    }
}
