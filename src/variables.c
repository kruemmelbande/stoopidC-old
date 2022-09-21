#include <string.h>
#include <stdio.h>
#include "global.h"

typedef struct Variable {
    char* name;
    char* value;
} Variable;

int currentVar = 0;
Variable variables[64];

void newVar(char* name, char* value) {
    variables[currentVar].name = name;
    variables[currentVar].value = value;

    currentVar += 1;
}

char* getVal(char* name) {
    for(int i = 0; i < currentVar; i++) {
        if(strcmp(variables[i].name, name) == 0) {
            return variables[i].value;
        }
    }

    return "0";
}