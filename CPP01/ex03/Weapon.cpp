/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:54:59 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/11 11:23:37 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string type)
	: _type(type) {}

Weapon::~Weapon() {}

const std::string&  Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
