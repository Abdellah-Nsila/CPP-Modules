/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 08:49:29 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 08:49:30 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	// Good Initialization
	try
	{
		Bureaucrat	b1 = Bureaucrat("Good", 42);
		Bureaucrat	b2;
		// Bureaucrat	b2 = b1; // This is copy constructor not assignement constructor
		b2 = b1; // This is assignement constructor
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Bad Initialization
	try
	{
		Bureaucrat	b1 = Bureaucrat("Bad", 1337);
		Bureaucrat	b2(b1);
	
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// High Exception
	try
	{
		Bureaucrat	high = Bureaucrat("High", 1);

		std::cout << high << std::endl;
		high.increGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Low Exception
	try
	{
		Bureaucrat	low = Bureaucrat("Low", 150);

		std::cout << low << std::endl;
		low.decreGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}