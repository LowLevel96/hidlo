#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "imageData.h"


int* imageData(char *filename){

    unsigned int *imagedata;
    // Do malloc for first 50 bytes
    imagedata = malloc(sizeof(int)*50);
    int bytevalue;
    int offset = -1;
    int index = 0;
    int increase = 1;
    FILE* file;
    file = fopen(filename, "rb");
 
    if(file){
             do{
                bytevalue = fgetc(file);
                imagedata[index] = bytevalue;
                index++;
                
                if(index==13){
                              offset = imagedata[10];
                }
                if((index > offset)&&(offset!=-1)){
                         break;     
                }

                /* When index with mod 50 be 0 increase memory size by 50 */
                if(index % 50 == 0){
                         increase++;
                         int *reallocState = (int *)realloc(imagedata, increase*50*sizeof(int));
                         if(!reallocState){
                                 printf("Could not allocate memory!");
                                 free(imagedata);
                         }else{
                               imagedata = reallocState;      
                         }
                }
                
             }while(bytevalue != EOF);
    }else{
          printf("Error Ocurred.");      
    }
    //Width, Height and Bits
    int width = imagedata[19]*256 + imagedata[18];
    int height =  imagedata[24 - 1]*256 + imagedata[23 - 1];
    int bits = imagedata[28]+imagedata[29];
    
    // Row Size and PixelArraySize
    int rowSize = floor((bits * width +31)/32)*4;
    int pixelArraySize = rowSize * abs(height) + offset;
    int actualRow = width * 3;
    int *reallocState = (int *)realloc(imagedata, pixelArraySize*sizeof(int));
        if(!reallocState){
                          printf("Could not allocate memory!");
                          free(imagedata);
        }else{
              imagedata = reallocState;      
        }
    int row = 0;
    while(index < pixelArraySize){
                bytevalue = fgetc(file);
                imagedata[index] = bytevalue;
                index++;
                
                row++;
                int padding = rowSize - actualRow;
                if(row == actualRow){
                       while(padding != 0){
                       bytevalue = fgetc(file);
                       padding--;
                       }
                       row = 0;
                }
                
    }
    fclose(file);
    
    return imagedata;
}
