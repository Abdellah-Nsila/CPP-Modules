#pragma once

#include "AForm.hpp"
#include "iostream"
#include "fstream"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm(std::string& target);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();

		void	executeAction() const;
		static AForm*	create(std::string& target);
};
