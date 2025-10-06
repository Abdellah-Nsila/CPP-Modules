/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:11:50 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/06 17:41:58 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MATERIAS_SLOTS; i++)
		this->_materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MATERIAS_SLOTS; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < MATERIAS_SLOTS; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m;
			std::cout << this->_materias[i]->getType() << std::endl;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < MATERIAS_SLOTS; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	return (0);
}
