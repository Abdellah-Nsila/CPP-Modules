/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:17:57 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/29 19:09:58 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal()
{
	this->type = "unknown";
	std::cout << "AbstractAnimal: Default constructor called" << std::endl;
}

AbstractAnimal::~AbstractAnimal()
{
	std::cout << "AbstractAnimal: Destructor called" << std::endl;
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal& copy)
{
	*this = copy;
	std::cout << "AbstractAnimal: Copy constructor called" << std::endl;
}

AbstractAnimal&	AbstractAnimal::operator=(const AbstractAnimal& copy)
{
	if (this != &copy)
		this->type = copy.type;
	std::cout << "AbstractAnimal: Copy assignment operator called" << std::endl;
	return (*this);
}

const std::string	AbstractAnimal::getType() const
{
	return (this->type);
}
