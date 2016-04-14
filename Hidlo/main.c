#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "struct.h"
//#include "mirror.h"

// Include getLine File for filename input
#include "getLine.h"

// Include imageData for loading from bmp file
#include "imageData.h"

/* ############## HERE INCLUDE 'h' FILES FOR IMAGE FILTER ############## */
#include "fMirror.h"
#include "fGray.h"
#include "fBrightness.h"
#include "fSaltAndPaper.h"
#include "fGreenReplace.h"
#include "getBGR.h"


/* ############## END OF INCLUDE 'h' FILES FOR IMAGE FILTER ############## */

// Write image Data to the file
#include "writeImageData.h"


int main() {
    // Load Filename and image data in imagedata pointer  
    // Filename input
    char *filename;
    filename = getln();
    
    char *filename2;
    filename2 = getln();
    
    // Load image data in imagedata pointer
    int* imagedata;
    imagedata = imageData(filename);
    free(filename);

    
    int* imagedata2;
    imagedata2 = imageData(filename2);
    free(filename2);

    
    // ==================================== //
    // Input all information in struct
    HEADER header;
    HEADER header2;
    INFOHEADER infoHeader;
    INFOHEADER infoHeader2;
    BGR BGR1;
    BGR BGRA;
    BGR2 BGR2;
       
    // Data Offset
    header2.offset = imagedata2[10]+imagedata2[11]+imagedata2[12]+imagedata2[13];
    header.offset = imagedata[10]+imagedata[11]+imagedata[12]+imagedata[13];
    printf("Data Offset: %d \n", header.offset);
    printf("Data Offset: %d \n", header2.offset);
    
    // InfoHeader Information    ( 40 Bytes )
    infoHeader.size = imagedata[14]+imagedata[15]+imagedata[16]+imagedata[17];
    infoHeader.width = imagedata[19]*256 + imagedata[18];
    infoHeader.height = imagedata[24 - 1]*256 + imagedata[23 - 1];
    infoHeader.bits = imagedata[28]+imagedata[29];
    infoHeader.compression = imagedata[30]+imagedata[31]+imagedata[32]+imagedata[33];
    infoHeader.imagesize = imagedata[35]*128;
    
    //InfoHeader Information 2
    infoHeader2.size = imagedata2[14]+imagedata2[15]+imagedata2[16]+imagedata2[17];
    infoHeader2.width = imagedata2[19]*256 + imagedata2[18];
    infoHeader2.height = imagedata2[24 - 1]*256 + imagedata2[23 - 1];
    infoHeader2.bits = imagedata2[28]+imagedata2[29];
    
    printf("\n\n-------------------------\n\n");
    printf("Info Header\n\n"); 
    printf("Header size: %d \n", infoHeader.size);
    printf("Image width: %d \n", infoHeader.width);
    printf("Image height: %d \n", infoHeader.height);
    printf("%d bit image: \n", infoHeader.bits);
    printf("Compression: %d \n", infoHeader.compression);
    
    // RowSize and Pixel Array Size
    int rowSize = floor((infoHeader.bits * infoHeader.width +31)/32)*4;
    int pixelArraySize = rowSize * abs(infoHeader.height) + header.offset;
    
    // RowSize and Pixel Array Size 2
    int rowSize2 = floor((infoHeader2.bits * infoHeader2.width +31)/32)*4;
    int pixelArraySize2 = rowSize2 * abs(infoHeader2.height) + header2.offset;
    
    // BGR Color
    BGR1.bgr = getBGR(infoHeader.height, infoHeader.width, header.offset, pixelArraySize, imagedata);
    // BGR Color 2
    BGRA.bgr = getBGR(infoHeader2.height, infoHeader2.width, header2.offset, pixelArraySize2, imagedata2);
   
   /* ------------------------------------------------------------ CALLING FUNCTIONS FOR FILTERS ----------------------------------------------------------------------------*/
   
   //Mirror Filter
   printf("\nIzaberite filter: \n");
   printf("1. Mirror\n");
   printf("2. Gray Scale\n");
   printf("3. Brightness\n");
   printf("4. Salt and Paper\n");
   printf("5. Binary\n");
   printf("6. Alpha Blend\n");
   printf("7. Green Replace\n");
   int ch;
   scanf("%d", &ch);
   switch(ch){
              case 1:
                   BGR2.bgr2 = mirror(infoHeader.width, infoHeader.height, BGR1.bgr);
                   free(BGR1.bgr);
                   break;
              case 2:
                   BGR2.bgr2 = gray(infoHeader.width, infoHeader.height, BGR1.bgr);
                   free(BGR1.bgr);
                   break;
              case 3:
                   BGR2.bgr2 = brightness(infoHeader.width, infoHeader.height, BGR1.bgr, 50);
                   free(BGR1.bgr);
                   break; 
              case 4:
                   BGR2.bgr2 = saltAndPaper(infoHeader.width, infoHeader.height, BGR1.bgr);
                   free(BGR1.bgr);
                   break; 
              case 5:
                   BGR2.bgr2 = binary(infoHeader.width, infoHeader.height, BGR1.bgr);
                   free(BGR1.bgr);
                   break;
              case 6:
                   BGR2.bgr2 = alphaBlend(infoHeader.width, infoHeader.height, BGR1.bgr, BGRA.bgr, 0.5);       //Alpha Channel from 0.0 - 1.0
                   free(BGR1.bgr);
                   free(BGRA.bgr);
                   break;
              case 7:
                   BGR2.bgr2 = greenReplace(infoHeader.width, infoHeader.height, BGR1.bgr, BGRA.bgr);
                   free(BGR1.bgr);
                   free(BGRA.bgr);
                   break;
              default:
                      printf("Niste uneli validan broj!");
   }

    
      
    /* ------------------------------------------------------------ END OF CALLING FUNCTIONS FOR FILTERS ----------------------------------------------------------------------------*/
    
   // Write Pixels to the image
   writeImageData(infoHeader.width, infoHeader.height, infoHeader.bits, BGR2.bgr2, imagedata, header.offset);
   free(BGR2.bgr2);
   free(imagedata);

    
    
 
    system("pause");
    return 0;
}
