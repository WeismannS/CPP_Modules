#include "Harl.hpp"




int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./ex06 [DEBUG|INFO|WARNING|ERROR]\n";
        return 1;
    }
    Harl pepe;
    pepe.complain(av[1]);
    return 0;
}