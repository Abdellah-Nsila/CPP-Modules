/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:52:36 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/06 15:31:49 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("undefined")
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

Character::Character(const Character &copy)
{
	*this = copy;
}

Character::~Character() 
{
	delete[] this->_materias;
}

Character&	Character::operator=(const Character& copy)
{
	if (this != &copy)
	{
		this->_name = copy.getName();
		for (int i = 0; i < 4; i++)
		{
			if (copy._materias[i])
				this->_materias[i] = copy._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
			this->_materias[i] = m;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 & idx < 4)
	{	
		delete this->_materias[idx];
		this->_materias[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 & idx < 4)
		this->_materias[idx]->use(target);
}
