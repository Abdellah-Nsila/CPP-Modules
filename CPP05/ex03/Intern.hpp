#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

enum FormType
{
	SHRUBBERY_CREATION,
	ROBOTOMY_REQUEST,
	PRESIDENTIAL_PARDON,
};

class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		Intern&	operator=(const Intern& copy);
		~Intern();

		AForm*	makeForm(std::string name, std::string target);
};
