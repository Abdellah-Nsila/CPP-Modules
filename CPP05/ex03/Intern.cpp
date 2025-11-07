#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& copy)
{
	(void)copy;
}

Intern&	Intern::operator=(const Intern& copy)
{
	(void)copy;
	return (*this);
}

Intern::~Intern()
{
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string	types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*creators[3])(std::string&) = {
		&ShrubberyCreationForm::create,
		&RobotomyRequestForm::create,
		&PresidentialPardonForm::create,
	};
	int	formsNum = sizeof(types) / sizeof(types[0]); 
	for (int i = 0; i < formsNum; i++)
	{
		if (types[i] == name)
			return (creators[i](target));
	}
	throw std::invalid_argument("Invalid Form name");
}
