#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//we need them args
#include <stdarg.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>



int getSizeOfChar(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
int countStrArr(char **strArr)
{
    printf("Counting: %s\n", strArr[0]);
    int i = 0;
    while (strArr[i] != NULL)
        i++;
        printf("%d\n",i);
    return i;
}
double* appendDouble(double *arr, double val)
{
    int size = sizeof(arr) / sizeof(double);
    double *newArr = (double *)malloc(sizeof(double) * (size + 1));
    for (int i = 0; i < size; i++)
        newArr[i] = arr[i];
    newArr[size] = val;
    return newArr;
}
char** appendString(char** arr, char* val)
{
    printf("%s\n", val);
    //get the size
   
    int size = countStrArr(arr);
    printf("size: %d\n", size);

    char** newArr = (char**)malloc(sizeof(char*) * (size + 1));
    for (int i = 0; i < size; i++)
        newArr[i] = arr[i];
    newArr[size] = val;
    for (int i = 0; i < size + 1; i++)
        printf("%s\n", newArr[i]);
    return newArr;
}


double getVariable(char **names, double *values, char *name){
    for(int i = 0; i < sizeof(names) / sizeof(char*); i++){
        if(strcmp(names[i], name) == 0){
            return values[i];
        }
    }
    return 0;
}

char ** split(char *str, char delim){
    //spilit the string into an array of strings
    //delim is the delimiter
    //str is the string to split
    //returns an array of strings
    
    printf("splitting %s\n", str);
    //get the size
    int size=getSizeOfChar(str);
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
    //char *filename = argv[1];
    char *filename = "C:\\Users\\kaisc\\Desktop\\susstuff\\stoopidc\\test.stpd";
    //open the file
    FILE* program;
    char ch;
    program = fopen(filename, "r");
    if (NULL == program) {
        printf("file can't be opened \n");
        return 0;
    }
    int size=0;
    int lines=0;
    do {
            ch = fgetc(program);
            if (ch == '\n') {
                lines++;
            }
            size++;
        //    printf("%c",ch);
    } while (ch != EOF);
        
    char buf[size];
    char ** linesArr;
    fclose(program);
    program=fopen(filename, "r");
    char *buf2=malloc(sizeof(char)*size);
    for (int i = 0; i < 3; i++)
    {  
        fgets(buf2, size, program);
        printf("%s\n", buf2);
        linesArr=appendString(linesArr, buf2);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", linesArr[i]);
    }
}
    

