#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <sys/types.h>

Form::Form(const std::string &name, u_int8_t grade, u_int8_t grade_exec)
    : name(name), grade_sign(grade), grade_exec(grade_exec), signed_(false) {
  if (grade < 1)
    throw Bureaucrat::gradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::gradeTooLowException();
}

Form::Form(const Form &form)
    : name(form.name), grade_sign(form.grade_sign),
      grade_exec(form.getExecGrade()), signed_(form.isSigned()) {}

Form::~Form() {}

u_int8_t Form::getExecGrade() const { return grade_exec; }
u_int8_t Form::getSignGrade() const { return grade_sign; }
Form &Form::operator=(const Form &form) {
  (void)form;
  return *this;
}

bool Form::isSigned() const { return signed_; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() >= getSignGrade())
    throw GradeTooLowException();
  else
    signed_ = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high for the form";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low for the form";
}

const char* Form::NotSignedException::what() const throw() {
    return "Form is not signed";
}