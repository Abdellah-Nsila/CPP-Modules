/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 09:44:37 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/20 09:38:57 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"



ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap: " << name << " Custom constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap: " << copy._name << " Copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& copy)
{
	std::cout << "ScavTrap: " << copy._name << " Copy assignment operator called" << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: " << this->_name << " Destructor called" <<  std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap: " << this->_name << " " << _name << " has no energy and can't attack!" << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap: " << this->_name << " " << _name << " is destroyed and can't attack!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap: " << this->_name << " " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap: " << this->_name << " is now in Gate keeper mode." << std::endl;
}

