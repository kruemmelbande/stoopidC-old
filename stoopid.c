#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//we need them args
#include <stdarg.h>
#include <time.h>
#include <unistd.h>
void main(int argc, char **argv){
    //get the filename from the args
    char *filename = argv[1];
    //open the file
    FILE *file = fopen(filename, "r");
    //print the file name
    printf("%s\n", filename);
    //print the contents
    while(!feof(file)){
        char c = fgetc(file);
        printf("%c", c);
    }
    //split the thing by the :
    
}