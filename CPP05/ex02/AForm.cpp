#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Unknown Form"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm(const AForm& copy) : _name(copy.getName()), _isSigned(copy.isSigned()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade()) {}

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	this->checkGrade(this->_signGrade);
	this->checkGrade(this->_executeGrade);
}

AForm&	AForm::operator=(const AForm& copy)
{
	if (this != &copy)
	{
		this->_isSigned = copy.isSigned();
	}
	return (*this);
}

AForm::~AForm() {}

const std::string&	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::isSigned() const
{
	return (this->_isSigned);
}

int	AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int	AForm::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void	AForm::setSigned(bool status)
{
	this->_isSigned = status;
}

void	AForm::checkGrade(int grade) const
{
	if (grade < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

void	AForm::checkRequiredGrade(int grade, int requiredGrade) const
{
	if (grade > requiredGrade)
		throw AForm::GradeTooLowException();
}

void	AForm::beSigned(const Bureaucrat& obj)
{
	this->checkRequiredGrade(obj.getGrade(), this->_signGrade);
	this->_isSigned = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Grade is Too High";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Grade is Too Low";
}

std::ostream&	operator<<(std::ostream& cout, const AForm& obj)
{
	cout << obj.getName()
		<< ", form status: " << (obj.isSigned() ? "Signed" : "Not Signed")
		<< ", form sign grade: " << obj.getSignGrade()
		<< ", form execute grade: " << obj.getExecuteGrade() << ".";
	return cout;
}
