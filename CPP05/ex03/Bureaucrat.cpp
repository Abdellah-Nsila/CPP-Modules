#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown Bureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()), _grade(copy.getGrade()) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->checkGrade(grade);
	this->_grade = grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
	{
		this->_grade = copy.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string&	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::checkGrade(int grade) const
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

void	Bureaucrat::increGrade()
{
	this->checkGrade(this->_grade - 1);
	this->_grade--;
}

void	Bureaucrat::decreGrade()
{
	this->checkGrade(this->_grade + 1);
	this->_grade++;
}

void	 Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign: "  << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{		
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute: "  << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is Too High";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low";
}

std::ostream&	operator<<(std::ostream& cout, const Bureaucrat& obj)
{
	cout << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return cout;
}
