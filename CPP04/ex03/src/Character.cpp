/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:36:48 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/06 18:43:26 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("undefined")
{
	for (int i = 0; i < MATERIAS_SLOTS; i++)
		this->_materias[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < MATERIAS_SLOTS; i++)
		this->_materias[i] = NULL;
}

Character::Character(const Character &copy)
{
	*this = copy;
}

Character::~Character() 
{
	for (int i = 0; i < MATERIAS_SLOTS; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
}

Character&	Character::operator=(const Character& copy)
{
	if (this != &copy)
	{
		this->_name = copy.getName();
		for (int i = 0; i < MATERIAS_SLOTS; i++)
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
	if (!m)
		return ;
	for (int i = 0; i < MATERIAS_SLOTS; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < MATERIAS_SLOTS)
	{	
		this->_materias[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < MATERIAS_SLOTS && this->_materias[idx])
		this->_materias[idx]->use(target);
}
