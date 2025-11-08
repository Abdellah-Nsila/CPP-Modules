/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:03:34 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 17:11:02 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	srand(time(0));
	AForm* scf = NULL;
	AForm* rrf = NULL;
	AForm* ppf = NULL;

	try
	{	
		Intern	someRandomInter = Intern();

		scf = someRandomInter.makeForm("shrubbery creation", "Home");
		std::cout << *scf << std::endl;

		rrf = someRandomInter.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;

		ppf = someRandomInter.makeForm("presidential pardon", "Jorshwa");
		std::cout << *ppf << std::endl;

		Bureaucrat	admin = Bureaucrat("Admin", 1);
		std::cout << admin << std::endl;

		admin.signForm(*scf);
		admin.signForm(*rrf);
		admin.signForm(*ppf);

		admin.executeForm(*scf);
		admin.executeForm(*rrf);
		admin.executeForm(*ppf);

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{	
		Intern	someRandomInter = Intern();

		AForm*	unkownForm;
		unkownForm = someRandomInter.makeForm("Unknown Form", "Unknown Target");
		std::cout << *unkownForm << std::endl;
		delete unkownForm;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete scf;
	delete rrf;
	delete ppf;
}
