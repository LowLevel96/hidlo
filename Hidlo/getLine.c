#include <stdio.h>
#include <stdlib.h>

#include "getLine.h"

char* getln()
{
    printf("Welcome LowLevel32\n");
    printf("Please, enter the image name: ");
    char *line = NULL, *tmp = NULL;
    int size = 0, index = 0;
    int ch = EOF;

    while (ch) {
        ch = getc(stdin);

        // Check if we need to stop. 
        if (ch == EOF || ch == '\n')
            ch = 0;

        // Check if we need to expand. 
        if (size <= index) {
            size += sizeof(char);
            tmp = (char *)realloc(line, size);
            if (!tmp) {
                free(line);
                line = NULL;
                break;
            }
            line = tmp;
        }

        // Actually store the thing.
        line[index++] = ch;
    }
    
    return line;
}
