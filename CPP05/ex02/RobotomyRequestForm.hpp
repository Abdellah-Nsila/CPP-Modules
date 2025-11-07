#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm(std::string& target);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		void	executeAction() const;
};
