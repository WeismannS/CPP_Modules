#ifndef ROBOTOMY_HPP 

#define ROBOTOMY_HPP 

#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm {
    private :
        std::string target;
public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
    void execute(const Bureaucrat& executor) ;
};


#endif