/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:03:30 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 11:17:36 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		Intern&	operator=(const Intern& copy);
		~Intern();

		class FormDosentExistExeption : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		AForm*	makeForm(std::string name, std::string target);
};
