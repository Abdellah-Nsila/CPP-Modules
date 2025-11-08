/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 08:50:02 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 17:10:18 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Unknown Form"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

Form::Form(const Form& copy) : _name(copy.getName()), _isSigned(false), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade()) {}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	this->checkGrade(this->_signGrade);
	this->checkGrade(this->_executeGrade);
}

Form&	Form::operator=(const Form& copy)
{
	if (this != &copy)
	{
		this->_isSigned = false;
	}
	return (*this);
}

Form::~Form() {}

const std::string&	Form::getName() const
{
	return (this->_name);
}

bool	Form::isSigned() const
{
	return (this->_isSigned);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void	Form::setSigned(bool status)
{
	this->_isSigned = status;
}

void	Form::checkGrade(int grade) const
{
	if (grade < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Form::GradeTooLowException();
	}
}

void	Form::checkRequiredGrade(int grade, int requiredGrade) const
{
	if (grade > requiredGrade)
		throw Form::GradeTooLowException();
}

void	Form::beSigned(const Bureaucrat& obj)
{
	this->checkRequiredGrade(obj.getGrade(), this->_signGrade);
	this->_isSigned = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade is Too High";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low";
}

std::ostream&	operator<<(std::ostream& cout, const Form& obj)
{
	cout << "Form name: " << obj.getName()
		<< ", Form status: " << (obj.isSigned() ? "Signed" : "Not Signed")
		<< ", Form sign grade: " << obj.getSignGrade()
		
		<< ", Form execute grade: " << obj.getExecuteGrade();
	return cout;
}
