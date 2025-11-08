/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 08:57:19 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 09:47:02 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	AForm*	form;
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
		{
			form = creators[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl; 	
			return (form);
		}
	}
	std::cout << "Intern couldn't create: " << name << ", because it doesn't exist" << std::endl;
	return (NULL);
}
