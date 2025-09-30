/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:17:57 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/29 19:09:58 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->type = "unknown";
	std::cout << "AAnimal: Default constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
	*this = copy;
	std::cout << "AAnimal: Copy constructor called" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& copy)
{
	if (this != &copy)
		this->type = copy.type;
	std::cout << "AAnimal: Copy assignment operator called" << std::endl;
	return (*this);
}

const std::string	AAnimal::getType() const
{
	return (this->type);
}
