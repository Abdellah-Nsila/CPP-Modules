/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:14:48 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 11:53:31 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
	std::cout << BOLDMAGENTA;
	std::cout << "[ DEBUG ]" << "\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!";
	std::cout << RESET << "\n";	
}

void Harl::info()
{
	std::cout << BOLDBLUE;
	std::cout << "[ INFO ]" << "\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!";
	std::cout << RESET << "\n";
}

void Harl::warning()
{
	std::cout << BOLDYELLOW;
	std::cout << "[ WARNING ]" << "\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.";
	std::cout << RESET << "\n";
}

void Harl::error()
{
	std::cout << BOLDRED;
	std::cout << "[ ERROR ]" << "\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << RESET << std::endl;
}

void	Harl::other()
{
	std::cout << BOLDWHITE;
	std::cout << "[ Probably complaining about insignificant problems ]";
	std::cout << RESET << std::endl;
}

int		Harl::getEnumLevel(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return (i);
	}
	return (-1);
}

void	Harl::complain( std::string level )
{
	switch (getEnumLevel(level))
	{
	case DEBUG:
		debug();
		std::cout << "\n";
	case INFO:
		info();
		std::cout << "\n";
	case WARNING:
		warning();
		std::cout << "\n";
	case ERROR:
		error();
		break ;	
	default:
		other();
		break;
	}
}
