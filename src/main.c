#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "global.h"

int main(int argc, char** argv) {
    //get the filename from the args
    char* filename = argv[1];
    if (filename == NULL) {
        filename = "test.stpd";
    }

    // open the file
    FILE* program;
    program = fopen(filename, "r");
    if (NULL == program) {
        printf("file can't be opened \n");
        return 1;
    }
    int size=0;

    fclose(program);
    program = fopen(filename, "r");
    char sizebuf[lineLimit];
    while(1) {
        fgets(sizebuf, lineLimit, program);
        size++;
        //check for end of file
        if (feof(program)){
            break;
        }
    }

    char buf[lineLimit];
    char buf2[size][lineLimit];
    fclose(program);
    program = fopen(filename, "r");
    
    for (int i = 0; i < size; i++) {  
        fgets(buf, lineLimit, program);
       
        strcpy(buf2[i], buf);
    }

    for (int i = 0; i < size; i++) {
        char* currentKeyword = split(buf2[i], ':', 0);
            
        if(!strcmp(currentKeyword, "var")) {
            printf("Test: var\n");
        } else if(!strcmp(currentKeyword, "out")) {
            printf("Test: out\n");
        } else if(!startsWith(buf2[i], "#") && !strcmp(buf2[i], " ")) {
            printf("Keyword %s not Found\n", currentKeyword);
            return 1;
        }
    }
}