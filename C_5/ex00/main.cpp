#include "Bureaucrat.hpp"
#include <exception>



std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
int main()
{
    try {
       Bureaucrat b("John Doe", 1);
       b.increaseGrade();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}
