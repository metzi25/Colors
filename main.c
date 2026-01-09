#include <stdio.h>
#include "color.h"
#include "image.h"
#include "gif.h"



int main() 
{
    printf("#1: Colors in console\n");
    int input;
    
    printf("Pick a color: (0-7): ");
    scanf("%d", &input);

    color_print((color)input);
    printf("\n");

    
    printf("#2: Images from input\n");
    image img;

    load_image(&img);

    printf("Image:\n");
    image_print(&img);


    printf("#3: Gif from file\n");
    gif g;
    char filename[50];

    printf("Gif filename: ");
    scanf("%s", filename);

    load_gif(filename, &g);
   
    print_gif(&g);

    return 0;
}