#include "PresidentialPardonForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <sys/types.h>
#include <ctime>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    (void) other;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form)
{
    os << form.getName() << ", sign grade" << form.getSignGrade() << ", exec grade " << form.getExecGrade();
    return os;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor)
{
    if (!requirement_fulfilled(executor.getGrade()))
        return;
    std::cout << "Presidential pardon granted to " << executor.getName() << std::endl;
    }