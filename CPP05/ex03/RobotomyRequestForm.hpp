/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:03:55 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 10:56:54 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
