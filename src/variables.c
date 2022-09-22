#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "global.h"

typedef struct Variable {
    char* name;
    char* value;
} Variable;

enum { MAX_SIZE = 64 };
int currentVar = 0;
Variable variables[MAX_SIZE];

void newVar(char* name, char* value) {
    variables[currentVar].name = name;
    variables[currentVar].value = value;
    currentVar += 1;
}

char* getVal(char* name) {
    for(int i = 0; i < currentVar; i++) {
        if(!strcmp(variables[i].name, name)) {
            return variables[i].value;
        }
    }

    return "ni";
}