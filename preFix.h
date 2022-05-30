#ifndef PREFIX_H
#define PREFIX_H
#include <stack>
#include <string>
class preFix {
private:
public:
    bool isOperator (char x);
    std::string preToInFix(std::string preFix_string);
};
#endif