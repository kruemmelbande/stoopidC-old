#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//we need them args
#include <stdarg.h>
#include <time.h>
#include <unistd.h>


int startswith(char *str, char *pre) {
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? 0 : strncmp(pre, str, lenpre) == 0;
}

int getSize(char *str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char* split(char* str, char splitter, int index) {
    char* out = malloc(256);

    for(int i = 0; i < getSize(str); i++) {
        if(str[i] == splitter) {
            index--;
            if(index == 0) {
                i++;
            }
        }

        if(index == 0) {
            int k = 0;

            for(int j = i; j < getSize(str); j++) {
                if(str[j] == splitter || j + 1 >= getSize(str)) {
                    out[k] = '\0';
                    return out;
                }

                out[k] = str[j];
                k++;
            }
        }
    }

    return NULL;
}


int main(int argc, char **argv) {
    static int lineLimit =256;
    //get the filename from the args
    char *filename = argv[1];
    if (filename == NULL) {
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

    fclose(program);
    program = fopen(filename, "r");
    char sizebuf[1024];
    while(1) {
            fgets(sizebuf,1024,program);
            size++;
            //check for end of file
            if (feof(program)){
                break;
            }
    }
    printf("%d\n",size);

    char buf[lineLimit];
    char buf2[size][lineLimit];
    fclose(program);
    program=fopen(filename, "r");
    
    for (int i = 0; i < size; i++) {  
        fgets(buf, lineLimit, program);
       
        strcpy(buf2[i], buf);
    }
    for (int i = 0; i < size; i++) {
        printf("%s", buf2[i]);
        if (startswith(buf2[i], "out")) {
            printf("print statement found in line %d \n",i+1);
            printf("you should print %s\n", split(buf2[i], ':', 0));
            printf("you should print %s\n", split(buf2[i], ':', 1));
            printf("you should print %s\n", split(buf2[i], ':', 2));
            printf("you should print %s\n", split(buf2[i], ':', 3));
        }
        if (startswith(buf2[i], "var")) {
            printf("variable declaration found in line %d \n",i+1);
        }
    }

}
