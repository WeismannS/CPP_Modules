#include "Form.hpp"
#include "Bureaucrat.hpp"
Form::Form(const std::string &name, u_int8_t grade_sign, u_int8_t grade_exec)
    : name(name), grade_sign(grade_sign), grade_exec(grade_exec), signed_(false) {
    if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
    if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), grade_sign(other.grade_sign), 
      grade_exec(other.grade_exec), signed_(other.signed_) {}

Form::~Form() {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        signed_ = other.signed_;
    }
    return *this;
}

const std::string& Form::getName() const { return name; }
u_int8_t Form::getSignGrade() const { return grade_sign; }
u_int8_t Form::getExecGrade() const { return grade_exec; }
bool Form::isSigned() const { return signed_; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > grade_sign)
        throw GradeTooLowException();
    signed_ = true;
}


bool Form::requirement_fulfilled(u_int8_t exec_grade) const {
    if (!signed_)
        throw NotSignedException();
    if (exec_grade > grade_exec)
        throw GradeTooLowException();
    return true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* Form::NotSignedException::what() const throw() {
    return "Form is not signed";
}