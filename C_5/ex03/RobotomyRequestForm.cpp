#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <sys/types.h>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form(other)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    (void) other;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form)
{
    os << form.getName() << ", sign grade" << form.getSignGrade() << ", exec grade " << form.getExecGrade();
    return os;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor)
{
    if (!requirement_fulfilled(executor.getGrade()))
        return;
    std::cout << "Drill Drill......z.z.z.z.z.z.z.!\n";
    std::srand(std::time(0) ^ std::clock());
    unsigned int hit = std::rand() & 1;
    if (hit)
        std::cout << "Robotomy success!\n";
    else
        std::cout << "Robotomy failed!\n";
    }