
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


Intern::Intern()
{
    std::cout << "Intern created" << std::endl;
}


Intern::~Intern()
{
    std::cout << "Intern destroyed" << std::endl;
}

Form *Intern::makeShrubberyForm(std::string &target)
{
    return new ShrubberyCreationForm(target);
}

Form *Intern::makePresidentialPardonForm(std::string &target)
{
    return new PresidentialPardonForm(target);
}

Form *Intern::makeRobotomyRequestForm(std::string &target)
{
    return new RobotomyRequestForm(target);
}

Form *Intern::makeForm(std::string &name, std::string &target)
{
    std::cout << "Intern making form" << std::endl;
    std::string forms[3] = {"Robotomy Request", "Presidential Pardon", "Shrubbery Creation"};
    Form* (Intern::*makers[])(std::string&) = {
        &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm, 
        &Intern::makeShrubberyForm
    };

    for (int i = 0; i < 3; i++)
        if (forms[i] == name)
            return (this->*makers[i])(target);
    std::cout << "Error: Form type '" << name << "' does not exist" << std::endl;
    return NULL;
}

