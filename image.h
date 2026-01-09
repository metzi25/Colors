#ifndef IMAGE_H
#define IMAGE_H

#include "color.h"

#define MAX_SIZE 30

typedef struct 
{
    int width;
    int height;
    color pixels[MAX_SIZE][MAX_SIZE];
} image;

void load_image(image* img);
void image_print(const image* img);

#endif
