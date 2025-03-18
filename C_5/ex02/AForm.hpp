#ifndef AFORM_HPP
#define AFORM_HPP

#include <sys/types.h>
#include <iostream>

class Bureaucrat;
class AForm {
private:
    const std::string name;
    const u_int8_t grade_sign;
    const u_int8_t grade_exec;
    bool signed_;

public:
    AForm(const std::string& name, u_int8_t grade_sign, u_int8_t grade_exec);
    virtual ~AForm();
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
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