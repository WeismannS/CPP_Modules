#include <iostream>


int main(int ac, char *av[])
{
    (void) ac;
    for (int i = 1; av[i]; i++)
        for (int y = 0; av[i][y]; y++)
            std::cout << (char)toupper(av[i][y]);
}