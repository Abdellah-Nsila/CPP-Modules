/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:11:50 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/09 18:09:41 by abnsila          ###   ########.fr       */
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
		if (this->_materias[i])
			delete this->_materias[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < MATERIAS_SLOTS; i++)
	{
		if (copy._materias[i])
			this->_materias[i] = copy._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < MATERIAS_SLOTS; i++)
		{
			if (this->_materias[i])
				delete this->_materias[i];
			if (copy._materias[i])
				this->_materias[i] = copy._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < MATERIAS_SLOTS; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m;
			return ;
		}
	}
	delete	m;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	AMateria	*clone;

	for (int i = 0; i < MATERIAS_SLOTS; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
		{
			clone = this->_materias[i]->clone();
			MateriaTracker::trackMateria(clone);
			return (clone);
		}
	}
	return (0);
}
