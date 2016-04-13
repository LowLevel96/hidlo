#include <stdio.h>
#include <stdlib.h>
#include "fBrightness.h"

unsigned short** brightness(int height, int width, unsigned short **bgr, int brightness){
   
   
   unsigned short **bgr2 = malloc((height*width) * sizeof(short)*3);
   int i;
   int j;
   int c;
   for(i = 0; i < height; i++){
         for(j = 0; j < width; j++){
               
               if((bgr2[i*width+j] = malloc(3 * sizeof(short))) == NULL){
                                  
                     free(bgr2);
                     break;
               }
               for(c = 0; c < 3; c++){
                     int newPixel = bgr[i*width+j][c]+brightness;
                     if(newPixel>255){ newPixel = 255; }
                     if(newPixel<0){ newPixel = 0; }
                     bgr2[i*width+j][c] = newPixel;
               }      
         }
   }
   return bgr2;
   
}
