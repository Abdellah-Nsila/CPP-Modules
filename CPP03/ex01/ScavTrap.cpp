/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 09:44:37 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 11:21:21 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"



ScavTrap::ScavTrap(string name) : ClapTrap(name)
{
	cout << "ScavTrap: " << name << " Custom constructor called" << endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	cout << "ScavTrap: " << copy._name << " Copy constructor called" << endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& copy)
{
	cout << "ScavTrap: " << copy._name << " Copy assignment operator called" << endl;
	ClapTrap::operator=(copy);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap: " << this->_name << " Destructor called" <<  endl;
}

void	ScavTrap::attack(const string& target)
{
	if (this->_energyPoints == 0)
	{
		cout << "ScavTrap: " << this->_name << " " << _name << " has no energy and can't attack!" << endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		cout << "ScavTrap: " << this->_name << " " << _name << " is destroyed and can't attack!" << endl;
		return ;
	}
	cout << "ScavTrap: " << this->_name << " " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << endl;
	this->_energyPoints--;
}

void	ScavTrap::guardGate(void)
{
	cout << "ScavTrap: " << this->_name << " is now in Gate keeper mode." << endl;
}

