#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//we need them args
#include <stdarg.h>
#include <time.h>
#include <unistd.h>




int getSize(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char ** split(char *str, char delim){
    //spilit the string into an array of strings
    //delim is the delimiter
    //str is the string to split
    //returns an array of strings
    
    printf("splitting %s\n", str);
    //get the size
    int size=getSize(str);
    printf("size: %d\n",size);
    //find the elements
    int elements=0;
    for(int i=0;i<size;i++){
        if(str[i]==delim){
            elements++;
        }
    }
    printf("%d\n",elements);
    //create the array
    char **array=malloc(sizeof(char*)*(elements+1));
    //fill the array
    int index=0;
    int start=0;
    int end=0;
    while(index<elements){
        while(str[end]!=delim){
            end++;
        }
        array[index]=malloc(sizeof(char)*(end-start+1));
        for(int i=start;i<end;i++){
            array[index][i-start]=str[i];
        }
        array[index][end-start]='\0';
        index++;
        start=end+1;
        end=start;
    }
    array[index]=NULL;
    return array;
}

int main(int argc, char **argv){
    //get the filename from the args
    char *filename = argv[1];
    //open the file
    FILE* program;
    char ch;
    program = fopen(filename, "r");
    if (NULL == program) {
        printf("file can't be opened \n");
    }
    int size=0;
    do {
            ch = fgetc(program);
            size++;
        //    printf("%c",ch);
    } while (ch != EOF);
        
    char buf[size];

    fclose(program);
    program=fopen(filename, "r");
    char *buf2=malloc(sizeof(char)*size);
    for (int i = 0; i < 3; i++)
    {  
        fgets(buf2, size, program);
        printf("%s", buf2);
    }
}
    

