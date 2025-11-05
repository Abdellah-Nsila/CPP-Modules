#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()), _grade(copy.getGrade()) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	try
	{
		this->checkGrade(grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
	{
		this->_name = copy.getName();
		this->_grade = copy.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string&	Bureaucrat::getName() const
{
	return (this->_name);
}

const int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

bool	Bureaucrat::checkGrade(int grade) const
{
	if (grade < 1)
	{
		throw GradeTooHighException();
		return (false);
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
		return (false);
	}
	return (true);
}

void	Bureaucrat::increGrade()
{
		try
	{
		if (this->checkGrade(this->_grade + 1))
		{
			this->_grade--;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::decreGrade()
{
	try
	{
		if (this->checkGrade(this->_grade - 1))
		{
			this->_grade--;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::ostream&	operator<<(std::ostream& cout, const Bureaucrat& obj)
{
	cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return cout;
}

class GradeTooHighException : public std::exception
{
	const char*	what() const noexcept
	{
		return "Grade is Too High";
	}
};

class GradeTooLowException : public std::exception
{
	const char*	what() const noexcept
	{
		return "Grade is Too Low";
	}
};
