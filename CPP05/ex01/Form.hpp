/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 08:50:05 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 09:08:56 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
	public:
		Form();
		Form(const Form& copy);
		Form(std::string name, int signGrade, int executeGrade);
		Form&	operator=(const Form& copy);
		~Form();

		const std::string&	getName() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;
		void				setSigned(bool status);

		void	beSigned(const Bureaucrat& obj);

		class GradeTooHighException : public std::exception
		{
			const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char*	what() const throw();
		};	
	private:
		void	checkGrade(int grade) const;
		void	checkRequiredGrade(int grade, int requiredGrade) const;
};

std::ostream&	operator<<(std::ostream& cout, const Form& obj);
