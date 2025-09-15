/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:36:49 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 11:21:21 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"



ClapTrap::ClapTrap(string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	cout << "ClapTrap: " << name << " Custom constructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	cout << "ClapTrap: " << copy._name << " Copy constructor called" << endl;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& copy)
{
	cout << "ClapTrap: " << copy._name << " Copy assignment operator called" << endl;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap: " << this->_name << " Destructor called" <<  endl;
}

void	ClapTrap::attack(const string& target)
{
	if (this->_energyPoints == 0)
	{
		cout << "ClapTrap " << _name << " has no energy and can't attack!" << endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		cout << "ClapTrap " << _name << " is destroyed and can't attack!" << endl;
		return ;
	}
	cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		cout << "ClapTrap " << _name << " is already destroyed!" << endl;
		return ;
	}
	cout << "ClapTrap " << this->_name << ", take " << amount << " points of damage!" << endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		cout << "ClapTrap " << _name << " has no energy and can't attack!" << endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		cout << "ClapTrap " << _name << " is destroyed and can't attack!" << endl;
		return ;
	}
	cout << "ClapTrap " << this->_name << ", be repaired with " << amount << " points of damage!" << endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
}
