#ifndef PRESIDENTAL_HPP 

#define PRESIDENTAL_HPP 

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm {
    private :
        std::string target;
public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();
    void execute(const Bureaucrat& executor) ;
};


#endif