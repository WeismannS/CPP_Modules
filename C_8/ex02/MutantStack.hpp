#ifndef MY_STACK_HPP
#define MY_STACK_HPP
#include <iostream>
#include <stack>
template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T> {
public:
  MutantStack() : std::stack<T>() {} ;
  MutantStack<T>(const MutantStack<T> &other) : std::stack<T>(other) {}  ;
  MutantStack<T> & operator=(const MutantStack<T> & other) {
              if (this != &other) {
                  std::stack<T>::operator=(other);
              }
              return *this;
          }
       ;
  virtual ~MutantStack() {};
  typename container::iterator begin() { return this->c.begin(); }
  typename container::iterator end() { return this->c.end(); }
  typedef typename container::iterator iterator;
};

#endif
