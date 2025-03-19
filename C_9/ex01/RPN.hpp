#pragma once

#include <string>

#include <stack>
#include <iostream>
class RPN
{
    std::stack<int> calcs;
    std::string express;
    public :
        RPN(std::string eq);
        RPN(const RPN &other);
        const RPN&operator=(const RPN &other);
        ~RPN();
        void skip_spaces(std::stringstream &s);
        int pop();
        int result();
};