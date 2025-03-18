#ifndef SPAN_HPP
#define SPAN_HPP

#include <ios>
#include <iostream>
#include <iterator>

class Span
{
    private :
        int      *storage;
        unsigned int max_size;
        unsigned int size;
     public :
    Span(unsigned int max_size);
    ~Span();
    Span(const Span &other);
    const int& operator[](unsigned int num);
    const Span& operator=(const Span &other);
    void addNumber(int new_int);
    int *begin() const;
    int *end() const;
    int shortestSpan() const;
    int longestSpan() const;
    template<typename T>
    void insert(typename T::iterator begin, typename T::iterator end)
    {
        unsigned int i;
        for (i = size; i < max_size && begin != end; i++, begin++)
            storage[i] = *begin;
        size = i;
    }
};




#endif