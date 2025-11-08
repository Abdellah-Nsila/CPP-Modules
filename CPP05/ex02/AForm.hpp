/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 08:50:22 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 09:20:03 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
	public:
		AForm();
		AForm(const AForm& copy);
		AForm(std::string name, int signGrade, int executeGrade);
		AForm&	operator=(const AForm& copy);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;
		void				setSigned(bool status);

		void	beSigned(const Bureaucrat& obj);
		void	execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception
		{
			const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char*	what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			const char*	what() const throw();
		};
	private:
		void	checkGrade(int grade) const;
		void	checkRequiredGrade(int grade, int requiredGrade) const;
	protected:
		virtual void	executeAction() const = 0;
};

std::ostream&	operator<<(std::ostream& cout, const AForm& obj);
