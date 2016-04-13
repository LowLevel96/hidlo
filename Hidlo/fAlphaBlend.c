#include <stdio.h>
#include <stdlib.h>

#include "fAlphaBlend.h"

unsigned short** alphaBlend(int height, int width, unsigned short **bgr, unsigned short **bgr1, double alpha){
   unsigned short **bgr2 = malloc((height*width) * sizeof(short)*3);
   int i;
   int j;
   int c;
   int gray = 0;
   int sum = 0;
   for(i = 0; i < height; i++){
         for(j = 0; j < width; j++){
               // Malloc for bgr2 2 D array
               if((bgr2[i*width+j] = malloc(3 * sizeof(short))) == NULL){
                     free(bgr2);
                     break;
               }
               
               for(c = 0; c < 3; c++){
                     bgr2[i*width+j][c] = bgr1[i*width+j][c]*alpha + bgr[i*width+j][c]*(1.0-alpha);
               }

         }      
   }
   return bgr2;  
}
  
