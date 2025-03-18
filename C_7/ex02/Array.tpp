#include "Array.hpp"
#include <cstring>
#include <exception>
#include <memory>
#include <stdexcept>


template <class T>
Array<T>::Array(Array &e)
{
    *this =  e;
}
template <class T>
Array<T>::Array(int n)
{
    arr = new T[n]();
    len = n;
}
template <class T>
Array<T>::Array() : len(0)
{
    arr = new T[0](); 
}
template <class T>
int Array<T>::size() const
{
    return len;
}
template <class T>
Array<T>::~Array()
{
    delete[] arr;
}
template <class T>
const Array<T> &Array<T>::operator=(const Array<T> &e) 
{
    if (this != &e) {
        delete[] arr;
        this->arr = new T[e.size()];
        for (int i = 0; i < e.size(); i++)
            arr[i] = e.arr[i];
        this->len = e.size();
    }
    return *this;
}
template <class T>
T &Array<T>::operator[](int n)
{
    if (n < 0 || n >= len)
        throw std::runtime_error("Out of bounds");
    return arr[n];
    
}
template <class T>
Array<T>::Array(T *e, int val)
{
    arr = new T[val];
    len = val - 1;
    for (int i = 0; i < val; i++)
        arr[i] = e[i];
}