/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:47:53 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/29 16:48:31 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "unknown";
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	*this = copy;
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& copy)
{
	if (this != &copy)
		this->type = copy.type;
	std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
	return (*this);
}

const std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Nothing!" << std::endl;
}
