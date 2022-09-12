#include <string>
#include <iostream>
#include "variable.h"

int Variable::setValue(std::string pValue) {
    value = pValue;
    return 0;
}

std::string Variable::getInformation() {
    std::string out;
    out += "----------\n";
    out += "Name: " + name + "\n";
    out += "Value: " + value + "\n";
    out += "Type: " + type + "\n";
    out += "----------\n";

    return out;
}

Variable::Variable(std::string pName, std::string pValue) {
    name = pName;
    value = pValue;
    type = getType(pValue);
}

Variable::Variable() {
    name = "placeholder";
    value = "placeholder";
    type = "placeholder";
}

std::string Variable::getType(std::string pValue) {
    int length = pValue.length();

    if(pValue == "True" || pValue == "False") {
        return "bool";
    } else {
        for(int i = 0; i < length; i++) {
            if(pValue[i] == '0' || pValue[i] == '1' || pValue[i] == '2' || pValue[i] == '3' || pValue[i] == '4' || pValue[i] == '5' || pValue[i] == '6' || pValue[i] == '7' || pValue[i] == '8' || pValue[i] == '9' || pValue[i] == '.') {
                continue;
            } else {
                return "string";
            }
        }

        return "num";
    }

    return "";
}