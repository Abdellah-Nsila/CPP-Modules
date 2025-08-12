/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:14:48 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/12 11:00:14 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"
# include "iostream"

using namespace std;

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
	cout << MAGENTA;
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	cout << RESET << endl;
	
}

void Harl::info()
{
	cout << BLUE;
	cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	cout << RESET << endl;
}

void Harl::warning()
{
	cout << YELLOW;
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
	cout << RESET << endl;
}

void Harl::error()
{
	cout << RED;
	cout << "This is unacceptable! I want to speak to the manager now.";
	cout << RESET << endl;
}

void	Harl::complain( string level )
{
	string	levels[] = {"Debug", "Info", "Warning", "Error"};
	void 		(Harl::*funcPtr[])() = {(&Harl::debug), (&Harl::info), (&Harl::warning), (&Harl::error)};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			(this->*(funcPtr[i]))();
	}
}
