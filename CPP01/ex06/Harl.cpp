/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:14:48 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/12 11:42:51 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

using namespace std;

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
	cout << BOLDMAGENTA;
	cout << "[ DEBUG ]" << "\n";
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!";
	cout << RESET << "\n";	
}

void Harl::info()
{
	cout << BOLDBLUE;
	cout << "[ INFO ]" << "\n";
	cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!";
	cout << RESET << "\n";
}

void Harl::warning()
{
	cout << BOLDYELLOW;
	cout << "[ WARNING ]" << "\n";
	cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.";
	cout << RESET << "\n";
}

void Harl::error()
{
	cout << BOLDRED;
	cout << "[ ERROR ]" << "\n";
	cout << "This is unacceptable! I want to speak to the manager now.";
	cout << RESET << endl;
}

void	Harl::other()
{
	cout << BOLDWHITE;
	cout << "[ Probably complaining about insignificant problems ]";
	cout << RESET << endl;
}

int		Harl::getEnumLevel(string level)
{
	string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return (i);
	}
	return (-1);
}

void	Harl::complain( string level )
{
	switch (getEnumLevel(level))
	{
	case DEBUG:
		debug();
		cout << "\n";
	case INFO:
		info();
		cout << "\n";
	case WARNING:
		warning();
		cout << "\n";
	case ERROR:
		error();
		break ;	
	default:
		other();
		break;
	}
}
