/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:14:48 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 11:49:07 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
	std::cout << BOLDMAGENTA;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!";
	std::cout << RESET << std::endl;
	
}

void Harl::info()
{
	std::cout << BOLDBLUE;
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!";
	std::cout << RESET << std::endl;
}

void Harl::warning()
{
	std::cout << BOLDYELLOW;
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.";
	std::cout << RESET << std::endl;
}

void Harl::error()
{
	std::cout << BOLDRED;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << RESET << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string	string_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (string_levels[i] == level)
		{	
			(this->*funcs[i])();
			break ;
		}
	}
}
