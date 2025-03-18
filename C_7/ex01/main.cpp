#include "iter.hpp"


template <typename T>
void high(T a)
{
    std::cout << a << "\n";
}

int main()
{
    int a[] = {1,2,3,4,5,6,7};
    std::string b[] = {"Hello","World","!","Ooof"};
    iter<int>(a, 7,high);
    iter<std::string>(b, 4,high);
}