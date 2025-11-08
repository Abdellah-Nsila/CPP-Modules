/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 08:50:00 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 08:50:01 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat(std::string name, int grade);
		Bureaucrat&	operator=(const Bureaucrat& copy);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;

		void	increGrade();
		void	decreGrade();

		void	 signForm(Form& obj);

		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		private:
			void	checkGrade(int grade) const;
};

std::ostream&	operator<<(std::ostream& cout, const Bureaucrat& obj);
