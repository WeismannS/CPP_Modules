#include <cctype>
#include <iostream>
#include <algorithm>
#include <ostream>
void screan(char c)
{
	std::cout << (char) toupper(c);
}
int main(int ac, char *av[])
{
    (void) ac;
    for (int i = 1; av[i]; i++)
    {
    	std::string str = av[i];
     	std::for_each(str.begin(), str.end(), screan);
      	std::cout << ' ';
    } 
    std::cout << std::endl;
}