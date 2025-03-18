

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << (int)b.getGrade();
    return os;
}

void test_bureaucrat_basic() {
    std::cout << "\n=== Testing Bureaucrat Basic Functionality ===\n";
    try {
        Bureaucrat b1("John", 75);
        std::cout << "Created bureaucrat: " << b1.getName() << " with grade " << (int)b1.getGrade() << std::endl;
        b1.increaseGrade();
        std::cout << "After increase: " << (int)b1.getGrade() << std::endl;
        b1.decreaseGrade();
        std::cout << "After decrease: " << (int)b1.getGrade() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_bureaucrat_limits() {
    std::cout << "\n=== Testing Bureaucrat Limits ===\n";
    try {
        std::cout << "Testing grade 0:" << std::endl;
        Bureaucrat b2("Alice", 0);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Testing grade 151:" << std::endl;
        Bureaucrat b3("Bob", 151);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Testing increment at grade 1:" << std::endl;
        Bureaucrat b4("Charlie", 1);
        b4.increaseGrade();
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Testing decrement at grade 150:" << std::endl;
        Bureaucrat b5("David", 150);
        b5.decreaseGrade();
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_form_basic() {
    std::cout << "\n=== Testing Form Basic Functionality ===\n";
    try {
        Form f1("Tax Form", 50, 30);
        Bureaucrat b1("Eve", 40);
        std::cout << "Created form with grade " << (int)f1.getSignGrade() << " and exec grade " << (int)f1.getExecGrade() << std::endl;
        std::cout << "Form signed status before: " << f1.isSigned() << std::endl;
        f1.beSigned(b1);
        std::cout << "Form signed status after: " << f1.isSigned() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_form_signing_limits() {
    std::cout << "\n=== Testing Form Signing Limits ===\n";
    try {
        Form f2("Contract", 40, 30);
        Bureaucrat b2("Frank", 50);
        std::cout << "Attempting to sign form with too low grade bureaucrat..." << std::endl;
        f2.beSigned(b2);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_form_copy() {
    std::cout << "\n=== Testing Form Copy ===\n";
    try {
        Form f1("Original", 50, 30);
        Bureaucrat b1("Grace", 40);
        f1.beSigned(b1);
        Form f2(f1);
        std::cout << "Original form signed status: " << f1.isSigned() << std::endl;
        std::cout << "Copied form signed status: " << f2.isSigned() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    test_bureaucrat_basic();
    test_bureaucrat_limits();
    test_form_basic();
    test_form_signing_limits();
    test_form_copy();
    
    return 0;
}