/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:25:30 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/20 12:49:05 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("unknown")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap: " << this->_name << " Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap: " << this->_name << " Custom constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "FragTrap: " << copy._name << " Copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& copy)
{
	if (this != &copy)
	{	
		ClapTrap::operator=(copy);
		std::cout << "FragTrap: " << this->_name << " Copy assignment operator called" << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << this->_name << " Destructor called" <<  std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap: " << this->_name << " is destroyed and can't attack!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "FragTrap: " << this->_name << " has no energy and can't attack!" << std::endl;
		return ;
	}
	std::cout << "FragTrap: " << this->_name << " attacks " << target 
	          << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: " << this->_name << " requests a positive high five! 🙌" << std::endl;
}

