#ifndef INTERN_HPP

#define INTERN_HPP
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern {
    public : 
    Intern();
    ~Intern();
    Intern(Intern &);
    const Intern& operator=(const Intern& copy);
    Form *makeForm(std::string &name, std::string &target);
    Form *makeShrubberyForm(std::string &target);
    Form *makeRobotomyRequestForm(std::string &target);
    Form *makePresidentialPardonForm(std::string &target);
    
};

#endif