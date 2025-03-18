#include "Span.hpp"
#include <algorithm>
#include <functional>
#include <limits>
#include <stdexcept>



Span::Span(unsigned int n) :storage(new int[n]), max_size(n),size(0)
{}

Span::~Span()
{
    delete[] storage;
}

void Span::addNumber(int n)
{
    if (size == max_size)
        throw std::length_error("Can't add more!");
    storage[size] = n;
    size++;
}

const int& Span::operator[](unsigned int num)
{
    if (num >= size || num < 0)
        throw std::length_error("Out of Boundary!");
    return storage[num];
}

int *Span::begin() const
{
    return storage;
}

int *Span::end() const
{
    return storage + size;
}
Span::Span(const Span &other) :  storage(new int[other.max_size]), max_size(other.max_size), size(other.size)
{
    std::copy(other.begin(), other.end(), storage);
}

const Span& Span::operator=(const Span &other)
{
    delete[] storage;
    std::copy(other.begin(), other.end(), storage);
   return *this; 
}

int Span::longestSpan() const
{
   return (*std::max_element(this->begin(), this->end())) - (*std::min_element(this->begin(),this->end()));
}



int Span::shortestSpan() const 
{
    Span tmp(*this);
    int smallestSpan = std::numeric_limits<int>::max();
    std::sort(tmp.storage, tmp.storage + size);
    for (unsigned int i = 0; i < size - 1; i++)
    {
        int span = tmp.storage[i+1] - tmp.storage[i];
        if ( span < smallestSpan)
            smallestSpan = span;
    }
    return smallestSpan; 
}

