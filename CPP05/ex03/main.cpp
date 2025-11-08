/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:03:34 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 10:05:02 by abnsila          ###   ########.fr       */
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
	try
	{	
		Intern	i1 = Intern();

		AForm*	f0;
		f0 = i1.makeForm("shrubbery creation", "Home");
		if (f0)
		{
			std::cout << *f0 << std::endl;
			delete f0;
		}

		AForm*	f1;
		f1 = i1.makeForm("bad form", "Target");
		if (f1)
		{
			std::cout << *f1 << std::endl;
			delete f1;
		}
		
		AForm*	f2;
		f2 = i1.makeForm("robotomy request", "Bender");
		if (f2)
		{
			std::cout << *f2 << std::endl;
			delete f2;
		}
		
		AForm*	f3;
		f3 = i1.makeForm("presidential pardon", "Jorshwa");
		if (f3)
		{
			std::cout << *f3 << std::endl;
			delete f3;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
