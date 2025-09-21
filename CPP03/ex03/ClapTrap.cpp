/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:36:49 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/20 11:23:38 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: " << this->_name << " Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: " << name << " Custom constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "ClapTrap: " << copy._name << " Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& copy)
{
	if (this != &copy)
	{	
		std::cout << "ClapTrap: " << copy._name << " Copy assignment operator called" << std::endl;
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: " << this->_name << " Destructor called" <<  std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is destroyed and can't attack!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy and can't attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << ", take " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is destroyed and can't be repaired!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy and can't be repaired!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << ", be repaired with " << amount << " points!" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
}