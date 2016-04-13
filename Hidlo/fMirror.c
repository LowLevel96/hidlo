#include <stdio.h>
#include <stdlib.h>
#include "fMirror.h"

unsigned short** mirror(int height, int width, unsigned short **bgr){
   
   
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
                     bgr2[i*width+j][c] = bgr[i*width+((width-1)-j)][c];
               }      
         }
   }
   return bgr2;
   
}
