#ifndef FORM_HPP
#define FORM_HPP

#include <sys/types.h>
#include <iostream>

class Bureaucrat;
class Form {
private:
    const std::string name;
    const u_int8_t grade_sign;
    const u_int8_t grade_exec;
    bool signed_;

public:
    Form(const std::string& name, u_int8_t grade_sign, u_int8_t grade_exec);
    virtual ~Form();
    Form(const Form& other);
    Form& operator=(const Form& other);
    const std::string& getName() const;
    u_int8_t getSignGrade() const;
    u_int8_t getExecGrade() const;
    bool isSigned() const;
    
    void beSigned(const Bureaucrat& bureaucrat);
    void signForm(const Bureaucrat& bureaucrat);
    virtual void execute(const Bureaucrat& executor) = 0;
    bool requirement_fulfilled(u_int8_t exec_grade) const;

    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };
    class NotSignedException : public std::exception {
        public:
            const char* what() const throw();
    };
};

#endif