#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <sys/types.h>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form(target, 2, 2)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form(other)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    (void) other;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form)
{
    os << form.getName() << ", sign grade" << form.getSignGrade() << ", exec grade " << form.getExecGrade();
    return os;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor)
{
    if (!requirement_fulfilled(executor.getGrade()))
        return;
    std::ofstream ofs((this->getName() + "_shrubbery").c_str());
    if (!ofs.is_open())
        throw std::runtime_error("Could not open file");
    ofs << "       _-_" << std::endl;
    ofs << "      (o o)" << std::endl;
    ofs << "     (  _  )" << std::endl;
    ofs << "    (  _  )" << std::endl;
    ofs << "   (  _  )" << std::endl;
    ofs << "  (  _  )" << std::endl;
    ofs << " (  _  )" << std::endl;
    ofs << "(  _  )" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
    ofs << "(_  _)" << std::endl;
}