

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

#include "AForm.hpp"
#include <iostream>
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << (int)b.getGrade();
    return os;
}

int main() {
    try {
        std::cout << "\n=== Testing ShrubberyCreationForm ===\n";
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrub("garden");
        
        std::cout << bob << std::endl;
        shrub.beSigned(bob);
        shrub.execute(bob);
        Bureaucrat lowGrade("LowGrade", 150);
        try {
            shrub.beSigned(lowGrade);
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        ShrubberyCreationForm unsignedShrub("park");
        try {
            unsignedShrub.execute(bob);
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        Bureaucrat alice("Alice", 1);
        ShrubberyCreationForm highGradeShrub("palace");
        std::cout << "\nTesting with high grade bureaucrat:\n";
        highGradeShrub.beSigned(alice);
        highGradeShrub.execute(alice);

    } catch (std::exception& e) {
        std::cout << "Main exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nTests completed.\n";
    return 0;
}