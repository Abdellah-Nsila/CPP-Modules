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
		~AForm();

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

std::ostream&	operator<<(std::ostream& cout, const AForm& obj);
