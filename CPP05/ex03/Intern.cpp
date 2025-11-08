/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 08:57:19 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 11:06:00 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

static AForm*	createSCF(std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm*	createRRF(std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	createPPF(std::string& target)
{
	return (new PresidentialPardonForm(target));
}

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

const char*	Intern::FormDosentExistExeption::what() const throw()
{
	return "Form Dosent Exist";
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm*	form;
	std::string	types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*creators[3])(std::string&) = {
		&createSCF,
		&createRRF,
		&createPPF,
	};
	int	formsNum = sizeof(types) / sizeof(types[0]);
	for (int i = 0; i < formsNum; i++)
	{
		if (types[i] == name)
		{
			form = creators[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl; 	
			return (form);
		}
	}
	throw FormDosentExistExeption();
	return (NULL);
}
