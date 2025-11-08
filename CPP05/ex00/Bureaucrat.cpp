/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 08:49:23 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 08:49:24 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
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
	