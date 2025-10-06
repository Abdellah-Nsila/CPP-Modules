/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:05:41 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/06 12:08:00 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& copy) : AMateria(copy) {}

Cure::~Cure() {}

Cure&	Cure::operator=(const Cure& copy)
{
	if (this != &copy)
		AMateria::operator=(copy);
	return (*this);
}

AMateria*	Cure::clone() const
{
	AMateria	*clonedCure;

	clonedCure = new Cure();
	return (clonedCure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
