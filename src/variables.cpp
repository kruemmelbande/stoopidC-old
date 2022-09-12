#include <iostream>
#include "variable.h"

extern "C" void addVar(std::string name, std::string value) {
    Variable vars[32];

    vars[0] = Variable(name, value);

    vars[0].getInformation();
}