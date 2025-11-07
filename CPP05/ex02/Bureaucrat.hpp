#pragma once

#include <iostream>
#include <string>

class AForm;

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

		void	 signForm(AForm& obj);

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
