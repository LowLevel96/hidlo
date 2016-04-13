#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fSaltAndPaper.h"

unsigned short** saltAndPaper(int height, int width, unsigned short **bgr){
   unsigned short **bgr2 = malloc((height*width) * sizeof(short)*3);
   int i;
   int j;
   int c;
   int gray = 0;
   int sum = 0;
   srand(time(NULL));
   for(i = 0; i < height; i++){
         for(j = 0; j < width; j++){
               // Malloc for bgr2 2 D array
               if((bgr2[i*width+j] = malloc(3 * sizeof(short))) == NULL){
                     free(bgr2);
                     break;
               }
               /* Gray Scale thing to do */
               sum = bgr[i*width+j][0] + bgr[i*width+j][1] + bgr[i*width+j][2];
               gray = sum/3;
               int randNum1 = rand()%100;
               if(randNum1 < 5){
               int randNum2 = rand()%2;

                                 if(randNum2 == 0){
                                 for(c = 0; c < 3; c++){
                                       bgr2[i*width+j][c] = 0;  
                                 }                
                                 }else{
                                 for(c = 0; c < 3; c++){
                                       bgr2[i*width+j][c] = 255;  
                                 }    
                                 }
                     }else{
                           for(c = 0; c < 3; c++){
                                       bgr2[i*width+j][c] = gray;  
                                 }
                     }
               
               sum = 0;
               gray = 0;
         }      
   }
   return bgr2;  
}
