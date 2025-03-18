#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <sys/types.h>
#include <iostream>
#include "Form.hpp"
class Bureaucrat {
    private: 
        std::string name;
        u_int8_t grade;
    public :
        class gradeTooHighException : public std::exception  {
                public :
                    const char *what() const throw();
        };
        class gradeTooLowException : public std::exception  {
                public :
                    const char *what() const throw();
        };
        Bureaucrat(const std::string& name, u_int8_t grade);
        const Bureaucrat& operator=(const Bureaucrat& other);
        Bureaucrat(Bureaucrat &copy_from);
        virtual ~Bureaucrat();
        const std::string& getName() const;
        u_int8_t getGrade() const;
        void increaseGrade();
        void decreaseGrade();
        void signForm(Form& form);
        
};

#endif