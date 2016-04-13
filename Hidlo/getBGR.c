#include <stdio.h>
#include <stdlib.h>

#include "getBGR.h"

unsigned short** getBGR(int height, int width, int offset, int pixelArraySize, unsigned int *imagedata){
    unsigned short **bgr = malloc((height*width) * sizeof(short)*3);
    int h = offset;
    int i;
    int j;
    int c;
    int row = 0;
    for(i = 0; i < height; i++){
         for(j = 0; j < width; j++){
          if((bgr[i*width+j] = malloc(3 * sizeof(short))) == NULL){                  
                free(bgr);
                break;
          }
          for(c = 0; c < 3; c++){
                bgr[i*width+j][c] = imagedata[h];
                h++;      
          }
         }
    }
    return bgr;
}
