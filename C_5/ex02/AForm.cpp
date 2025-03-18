#include "AForm.hpp"
#include "Bureaucrat.hpp"
AForm::AForm(const std::string &name, u_int8_t grade_sign, u_int8_t grade_exec)
    : name(name), grade_sign(grade_sign), grade_exec(grade_exec), signed_(false) {
    if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
    if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), grade_sign(other.grade_sign), 
      grade_exec(other.grade_exec), signed_(other.signed_) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        signed_ = other.signed_;
    }
    return *this;
}

const std::string& AForm::getName() const { return name; }
u_int8_t AForm::getSignGrade() const { return grade_sign; }
u_int8_t AForm::getExecGrade() const { return grade_exec; }
bool AForm::isSigned() const { return signed_; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > grade_sign)
        throw GradeTooLowException();
    signed_ = true;
}


bool AForm::requirement_fulfilled(u_int8_t exec_grade) const {
    if (!signed_)
        throw NotSignedException();
    if (exec_grade > grade_exec)
        throw GradeTooLowException();
    return true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* AForm::NotSignedException::what() const throw() {
    return "AForm is not signed";
}