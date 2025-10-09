/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaTracker.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:03:53 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/09 16:37:27 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaTracker.hpp"

AMateria	*MateriaTracker::_materias[MAX_MATERIAS] = { NULL };
int			MateriaTracker::_count;

MateriaTracker::MateriaTracker() {}

MateriaTracker::~MateriaTracker()
{
	MateriaTracker::clean();
}

MateriaTracker::MateriaTracker(const MateriaTracker& copy)
{
	(void)copy;
}

MateriaTracker&	MateriaTracker::operator=(const MateriaTracker& copy)
{
	(void)copy;
	return (*this);
}

void		MateriaTracker::trackMateria(AMateria *m)
{
	if (!m)
		return ;
	if (_count >= MAX_MATERIAS)
	{
		delete m;
		return ;
	}
	_materias[_count] = m;
	_count++;
}

void		MateriaTracker::deleteMateria(AMateria *ptr)
{
	if (!ptr)
		return ;
	for (int i = 0; i < _count; i++)
	{
		if (ptr == _materias[i])
		{
			delete _materias[i];
			_materias[i] = NULL;
			return ;
		}
	}
}

void		MateriaTracker::clean()
{
	for (int i = 0; i < _count; i++)
	{
		if (_materias[i])
			delete _materias[i];
		_materias[i] = NULL;
	}
	_count = 0;
}
