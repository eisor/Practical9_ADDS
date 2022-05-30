#include "preFix.h"
#include <iostream>
#include <string>

using namespace std;


int main() {
    string str;
    preFix a;
    cout<<"Please enter prefix expression: ";
    getline(cin,str);
    cout<< "Infix expression: " <<a.preToInFix(str) << endl;
    return 0;
}