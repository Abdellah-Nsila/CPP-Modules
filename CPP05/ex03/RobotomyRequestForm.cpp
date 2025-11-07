#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Unknown RobotomyRequestForm", 72, 42), _target("Unknown target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 42), _target(target)
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
		AForm::operator=(copy);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::executeAction() const
{
	srand(time(0));
	if (rand() % 2)
		std::cout << "BZZZZZZZZZZZ... " << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "BZZZZZZZZZZZ... " << "Robotomy failed on " << this->_target << std::endl;
}
