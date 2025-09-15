/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:55:44 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 10:05:51 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

const std::string&	HumanB::getName() const
{
	return (this->_name);
}

const Weapon*	HumanB::getWeapon() const
{
	return (this->_weapon);
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	if (this->getWeapon())
		std::cout << this->getName() << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->getName() << " have no weapon" << std::endl;
}
