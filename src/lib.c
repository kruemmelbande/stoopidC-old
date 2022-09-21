#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    if(index == 0) {
        int j = 0;
    
        for(int i = 0; i < getSize(str); i++) {
            if(str[i] == splitter || str[i] == '\0') {
                out[j] = '\0';
                return out;
            }

            out[j] = str[i];
            j++;
        }
    } else {
        int j = index;

        for(int i = 0; i < getSize(str); i++) {
            if(str[i] == splitter) {
                j -= 1;
            }

            if(j == 0) {
                int k = 1;

                while (str[k + i] != splitter && str[k + i] != '\0') {
                    out[k - 1] = str[k + i];
                    k++;
                }

                out[k] = '\0';
                return out;
            }
        }
    }

    return NULL;
}