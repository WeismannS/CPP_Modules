#include "Bureaucrat.hpp"
#include <istream>



Bureaucrat::Bureaucrat(const std::string &name, u_int8_t grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::gradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::gradeTooLowException();
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << (int)b.getGrade();
    return os;
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
