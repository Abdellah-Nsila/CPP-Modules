#pragma once

#include "iostream"
#include "string"

class Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat(std::string name, int grade);
		Bureaucrat&	operator=(const Bureaucrat& copy);
		~Bureaucrat();

		const std::string&	getName() const;
		const int			getGrade() const;

		bool	checkGrade(int grade) const;
		void	increGrade();
		void	decreGrade();
};

std::ostream&	operator<<(std::ostream& cout, const Bureaucrat& obj);
