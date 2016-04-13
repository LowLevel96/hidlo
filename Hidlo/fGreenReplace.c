#include <stdio.h>
#include <stdlib.h>

#include "fGreenReplace.h"

unsigned short** greenReplace(int height, int width, unsigned short **bgr, unsigned short **bgr1){
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
               int r = bgr1[i*width+j][2];
               int g = bgr1[i*width+j][1];
               int b = bgr1[i*width+j][0];
               /* Green replace */
               int green[3];
               if(g > r+30 && g > b-20){
                     green[0] = bgr[i*width+j][0];
                     green[1] = bgr[i*width+j][1];
                     green[2] = bgr[i*width+j][2];
               }else{
                     green[0] = bgr1[i*width+j][0];
                     green[1] = bgr1[i*width+j][1];
                     green[2] = bgr1[i*width+j][2];      
               }
               
               for(c = 0; c < 3; c++){
                     bgr2[i*width+j][c] = green[c];
               }
               sum = 0;
               gray = 0;
         }      
   }
   return bgr2;  
}
 
