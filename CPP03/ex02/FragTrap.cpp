/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:25:30 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/17 14:41:26 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

using namespace std;

FragTrap::FragTrap(string name) : ClapTrap(name)
{
	cout << "FragTrap: " << name << " Custom constructor called" << endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	cout << "FragTrap: " << copy._name << " Copy constructor called" << endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& copy)
{
	cout << "FragTrap: " << copy._name << " Copy assignment operator called" << endl;
	ClapTrap::operator=(copy);
	return (*this);
}

FragTrap::~FragTrap()
{
	cout << "FragTrap: " << this->_name << " Destructor called" <<  endl;
}

void	FragTrap::attack(const string& target)
{
	if (this->_energyPoints == 0)
	{
		cout << "FragTrap: " << this->_name << " has no energy and can't attack!" << endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		cout << "FragTrap: " << this->_name << " is destroyed and can't attack!" << endl;
		return ;
	}
	cout << "FragTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << endl;
	this->_energyPoints--;
}

void	FragTrap::highFivesGuys(void)
{
	cout << "FragTrap: " << this->_name << ", Hight fives guys" << endl;
}
