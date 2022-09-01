#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//we need them args
#include <stdarg.h>
#include <time.h>
#include <unistd.h>


int startswith(char *str, char *pre)
{
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? 0 : strncmp(pre, str, lenpre) == 0;
}

int getSize(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}


int main(int argc, char **argv){
    //get the filename from the args
    char *filename = argv[1];
    if (filename == NULL){
        filename="test.stpd";
    }
    //open the file
    FILE* program;
    char ch;
    program = fopen(filename, "r");
    if (NULL == program) {
        printf("file can't be opened \n");
        return 1;
    }
    int size=0;
    do {
            ch = fgetc(program);
            if (ch!=EOF || ch!='\n' || ch!='\t' || ch!=' '){
                size++;}
            size++;
            printf("%c",ch);
    } while (ch != EOF);
    printf("\n%d\n",size);
    
    char buf[256];
    char buf2[size][256];
    fclose(program);
    program=fopen(filename, "r");
    
    for (int i = 0; i < size; i++)
    {  
        fgets(buf, size, program);
       
        strcpy(buf2[i], buf);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%s", buf2[i]);
        if (startswith(buf2[i], "out"))
        {
            printf("print statement found in line %d \n",i+1);
        }
        if (startswith(buf2[i], "var"))
        {
            printf("variable declaration found in line %d \n",i+1);
        }

    }

}
    

