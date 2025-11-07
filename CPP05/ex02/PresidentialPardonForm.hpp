#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm(std::string& target);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		void	executeAction() const;
};
