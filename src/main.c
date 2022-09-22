#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "global.h"
#include "variables.h"

int main(int argc, char** argv) {
    //get the filename from the args
    char* filename = argv[1];
    if (filename == NULL) {
        filename = "test.stpd";
    }
    int silent=0;
    int log=0;
    char* logname = "";
    for (size_t i = 0; i < argc; i++)
    {
        if (argv[i] == "--silent") {
           log=1;
        }
        if (argv[i] == "--log") {
           log=1;
           logname = argv[i+1];
        }
    }
    FILE* logf;
    logf=fopen(logname,"w");
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
            newVar(split(split(buf2[i], ':', 1), '=', 0), split(split(buf2[i], ':', 1), '=', 1));
        } else if(!strcmp(currentKeyword, "out")) {
            if (log==1) {
                fprintf(logf, "%s", getVal(split(buf2[i], ':', 1)));
            }
            if (silent==0) {
                printf("%s", getVal(split(buf2[i], ':', 1)));
            }
            printf("%s\n", getVal((split(buf2[i], ':', 1))));
        } else if(!startsWith(buf2[i], "#") && strcmp(currentKeyword, " ") > 0) {
            printf("Keyword %s not Found\n", currentKeyword);
            return 1;
        }
    }
}