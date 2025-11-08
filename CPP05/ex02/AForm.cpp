/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 08:50:18 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 17:10:32 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Unknown Form"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm(const AForm& copy) : _name(copy.getName()), _isSigned(false), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade()) {}

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	this->checkGrade(this->_signGrade);
	this->checkGrade(this->_executeGrade);
}

AForm&	AForm::operator=(const AForm& copy)
{
	if (this != &copy)
	{
		this->_isSigned = false;
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

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_isSigned)
	{
		throw AForm::FormNotSignedException();
	}
	checkRequiredGrade(executor.getGrade(), this->getExecuteGrade());
	this->executeAction();
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade is Too High";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low";
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed yet";
}

std::ostream&	operator<<(std::ostream& cout, const AForm& obj)
{
	cout << "Form name: " << obj.getName()
		<< ", Form status: " << (obj.isSigned() ? "Signed" : "Not Signed")
		<< ", Form sign grade: " << obj.getSignGrade()
		<< ", Form execute grade: " << obj.getExecuteGrade();
	return cout;
}
