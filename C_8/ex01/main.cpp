#include "Span.hpp"
#include <vector>


int main()
{
Span sp = Span(7);
std::vector<int> b;

b.push_back(12);
b.push_back(13);
b.push_back(14);
b.push_back(15);

sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
sp.insert<std::vector<int> >(b.begin(), b.end());


for (int *i = sp.begin(); i != sp.end(); i++)
std::cout << *i << "\n";
}