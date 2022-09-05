#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>
#include <unistd.h>
#include "lib.h"
#include "global.h"

int startsWith(char* str, char* pre) {
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? 0 : strncmp(pre, str, lenpre) == 0;
}

int getSize(char* str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char* split(char* str, char splitter, int index) {
    char* out = malloc(lineLimit);

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