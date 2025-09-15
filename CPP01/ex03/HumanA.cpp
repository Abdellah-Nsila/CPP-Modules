/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:55:22 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 09:44:17 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon )
: _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

const std::string&	HumanA::getName() const
{
	return (this->_name);
}

void	HumanA::attack()
{
	std::cout << this->getName() << " attacks with their " << this->_weapon.getType() << std::endl;
}
