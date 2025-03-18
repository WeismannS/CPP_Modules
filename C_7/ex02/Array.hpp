#ifndef ARRAY_HPP

#define ARRAY_HPP
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <iostream>
template <class T>
class Array {
    private :
        T *arr;
        int len;
    public :
        Array<T>(T *arr, int val);
        Array<T>();
        ~Array();
        Array(int n);
        const Array<T> &operator=(const Array&);
        Array(Array &e);
        int size() const;
        T &operator[](int c);
};
#endif