#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try {
        Intern someRandomIntern;
        
        Bureaucrat supervisor("Supervisor", 1);
        std::string robotName = "Robotomy Request";
        std::string presName = "Presidential Pardon";
        std::string shrubName = "Shrubbery Creation";
        std::string target = "Target";
        Form* rrf = someRandomIntern.makeForm(robotName, target);
        Form* ppf = someRandomIntern.makeForm(presName, target);
        Form* scf = someRandomIntern.makeForm(shrubName, target);

        if (rrf) {
            std::cout << "\nTesting Robotomy Request Form:" << std::endl;
            supervisor.signForm(*rrf);
            rrf->execute(supervisor);
            delete rrf;
        }

        if (ppf) {
            std::cout << "\nTesting Presidential Pardon Form:" << std::endl;
            supervisor.signForm(*ppf);
            ppf->execute(supervisor);
            delete ppf;
        }

        if (scf) {
            std::cout << "\nTesting Shrubbery Creation Form:" << std::endl;
            supervisor.signForm(*scf);
            scf->execute(supervisor);
            delete scf;
        }
        std::string invalidName = "Invalid Form";
        Form* invalid = someRandomIntern.makeForm(invalidName, target);
        if (!invalid) {
            std::cout << "\nInvalid form name test passed: form was not created" << std::endl;
        }
        Bureaucrat junior("Junior", 150);
        Form* testForm = someRandomIntern.makeForm(robotName, target);
        if (testForm) {
            std::cout << "\nTesting form with low-ranked bureaucrat:" << std::endl;
            try {
                junior.signForm(*testForm);
            } catch (const std::exception& e) {
                std::cout << "Expected exception: " << e.what() << std::endl;
            }
            delete testForm;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}