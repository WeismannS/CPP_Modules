#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T &arr, int element)
{
    return std::find(arr.begin(), arr.end(), element);
}
#endif