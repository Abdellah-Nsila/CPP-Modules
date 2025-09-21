/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:25:30 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/20 09:38:57 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"



FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap: " << name << " Custom constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "FragTrap: " << copy._name << " Copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& copy)
{
	std::cout << "FragTrap: " << copy._name << " Copy assignment operator called" << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << this->_name << " Destructor called" <<  std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "FragTrap: " << this->_name << " has no energy and can't attack!" << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap: " << this->_name << " is destroyed and can't attack!" << std::endl;
		return ;
	}
	std::cout << "FragTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: " << this->_name << ", Hight fives guys" << std::endl;
}
