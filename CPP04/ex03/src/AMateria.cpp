/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:56:26 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/04 18:20:27 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//TODO: Be carful of what param type it is refrence or pointer , const or simple ??

AMateria::AMateria()
{
	
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &copy)
{

}

AMateria::~AMateria()
{
	
}

AMateria&	AMateria::operator=(const AMateria& copy)
{

}

std::string const	&AMateria::getType() const
{
	return (this->type);
}
