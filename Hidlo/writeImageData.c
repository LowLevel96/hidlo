

#include <stdio.h>
#include <stdlib.h>

#include "writeImageData.h"

void writeImageData(int width, int height, int bits, unsigned short **bgr2, int *imagedata, unsigned int offset){
   FILE *bmpCompression;
   int actualRow = width * 3;
   int rowSize = floor((bits * width +31)/32)*4;
   bmpCompression = fopen("maca3.bmp", "wb");
   int row = 0;
   int g = 0;
   while(g<138){
                fputc(imagedata[g], bmpCompression);
                g++;          
   }
   
   int index = 138;
   int k;
   int i;
   int j;
   int c;
   for(i = 0; i < height; i++){
         for(j = 0; j < width; j++){
             for(c = 0; c < 3; c++){
                   imagedata[index] = bgr2[i*width+j][c];
                   fputc(imagedata[index], bmpCompression);  
                   index++;    
             }
         }
         int padding = rowSize - actualRow;
         while(padding != 0){
                      imagedata[index] = 0;
                      fputc(imagedata[index], bmpCompression);
                      index++;
                      padding--;
         }
   }
   
   fclose(bmpCompression);
}
