#include <string>

class Variable {
    public:
        int setValue(std::string pValue);
        std::string getInformation();

        Variable(std::string pName, std::string pValue);

        Variable();

    private:
        std::string type;
        std::string value;
        std::string name;

        std::string getType(std::string pValue);
};