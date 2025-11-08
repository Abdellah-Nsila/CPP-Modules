/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:04:03 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 10:56:51 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
};
