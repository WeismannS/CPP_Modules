#include "Bureaucrat.hpp"
#include <istream>



Bureaucrat::Bureaucrat(const std::string &name,u_int8_t grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::gradeTooLowException();
    else if (grade > 150)
        throw Bureaucrat::gradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat &copy)
    : name(copy.name), grade(copy.grade)
{
}

const char * Bureaucrat::gradeTooLowException::what() const throw() {
    return  "Grade is too low!!";
}

const char * Bureaucrat::gradeTooHighException::what() const throw() {
   return "Grade is too high!!!"; 
}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy_from) 
{
    this->name = copy_from.name;
    this->grade = copy_from.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const {
    return this->name;
}

u_int8_t Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::increaseGrade() {
    if (this->grade == 1)
        throw Bureaucrat::gradeTooHighException();
    this->grade--;
}

void Bureaucrat::decreaseGrade() {
    if (this->grade == 150)
        throw Bureaucrat::gradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(Form & form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << name << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->getName() << " couldn't sign " << name 
                 << " because " << e.what() << std::endl;
    }
}