#include "preFix.h"
#include <stack>
#include <string>
#include <iostream>

bool preFix::isOperator(char op)
{
    switch (op)
    {
    case '+':
        return true;
    case '-':
        return true;
    case '*':
        return true;
    case '/':
        return true;
    }
    return false;
}

std::string preFix::preToInFix(std::string preFix_string)
{
    std::stack<std::string> inFixStack;
    std::stack<int> resultStack;
    char op;
    std::string str = "";
    for (int i = preFix_string.size(); i > -1; i--)
    {
        op = preFix_string[i];

        if (isOperator(op) == true)
        {
            if (inFixStack.size() < 2)
            {
                return "Error";
            }
            // get first operation

            std::string op1 = inFixStack.top();
            inFixStack.pop();

            // get second operation
            std::string op2 = inFixStack.top();
            inFixStack.pop();
            
            std::string temp = "(" + op1 + op + op2 + ")";
            
            inFixStack.push(temp);

            // get Result
            int op1Result = resultStack.top();
            resultStack.pop();

            int op2Result = resultStack.top();
            resultStack.pop();

            switch (op)
            {
            case '+':
                resultStack.push(op1Result + op2Result);
                break;
            case '-':
                resultStack.push(op1Result - op2Result);
                break;
            case '*':
                resultStack.push(op1Result * op2Result);
                break;
            case '/':
                resultStack.push(op1Result / op2Result);
                break;
            }
        }
    
        else 
        {
            if (op != ' ') {
                // std::cout << "Pushed: " << std::string(1, op) << std::endl;
                resultStack.push(op - '0');
                // std::cout << atol(op.c_str())) << std::endl;
                inFixStack.push(std::string(1, op));
            }
        }
    }
    // if (inFixStack.size() > 1)
    // {
    //     return "Error";
    // }
    return inFixStack.top() + " = " + std::to_string(resultStack.top());
}