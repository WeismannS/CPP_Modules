#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

void RPN::skip_spaces(std::stringstream &s) {
  char c;
  c = s.get();
  while (c == ' ' || c == '\t')
    c = s.get();
  s.unget();
}

int calculate(int c, int b, char op) {
  if (op == '+')
    return c + b;
  if (op == '-')
    return c - b;
  if (op == '/')
    return c / b;
  if (op == '*')
    return c * b;
  throw std::runtime_error("invalid operator");
}

RPN::RPN(std::string formula) : express(formula) {}

RPN::~RPN()
{}
int RPN::pop() {
  if (this->calcs.size() > 0) {
    int top = this->calcs.top();
    calcs.pop();
    return top;
  }
  throw std::runtime_error("incorrect expression");
}

int RPN::result() {
  std::stringstream a(this->express);
  while (a.rdbuf()->in_avail()) {
    int token;
    char op;
    skip_spaces(a);
    std::streampos originalPosition = a.tellg();
    if (!(a >> token)) {
      a.clear();
      a.seekg(originalPosition);
      skip_spaces(a);
      op = a.get();
      if (op == '+' || op == '-' || op == '/' || op == '*') {
        int right = this->pop();
        int left = this->pop();
        this->calcs.push(calculate(left, right, op));
        continue;
      }
      throw std::invalid_argument("Invalid operator");
    } else {
      this->calcs.push(token);
    }
  }
  return this->calcs.top();
}
