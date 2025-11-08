/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:04:00 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/08 10:57:28 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Unknown ShrubberyCreationForm", 145, 137), _target("Unknown target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
		AForm::operator=(copy);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::executeAction() const
{
	std::string		outFile_path = (this->_target + "_shrubbery");
	std::ofstream	outFile(outFile_path.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Can't open " << outFile_path << std::endl;
		return ;
	}
	std::cout << "Shrubbery has been created at " << outFile_path << std::endl;
	outFile << "=================== ASCII trees ==================\n"
	<< "                        # #### ####" << '\n'
    << "                  ### \\/#|### |/####" << '\n'
    << "                 ##\\/#/ \\||/##/_/##/_#" << '\n'
    << "               ###  \\/###|/ \\/ # ###" << '\n'
    << "             ##_\\_#\\_\\## | #/###_/_####" << '\n'
    << "            ## #### # \\ #| /  #### ##/##" << '\n'
    << "             __#_--###`  |{,###---###-~" << '\n'
    << "                       \\ }{" << '\n'
    << "                        }}{" << '\n'
    << "                        }}{" << '\n'
    << "                        {{}" << '\n'
    << "                  , -=-~{ .-^- _"
	<< std::endl;
	outFile.close();
}
