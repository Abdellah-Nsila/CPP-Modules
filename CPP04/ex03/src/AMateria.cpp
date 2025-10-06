/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:56:26 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/06 15:27:27 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("undefined") {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

AMateria::~AMateria() {}

AMateria&	AMateria::operator=(const AMateria& copy)
{
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}
