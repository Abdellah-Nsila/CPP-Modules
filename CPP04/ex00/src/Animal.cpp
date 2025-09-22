/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:17:57 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/22 16:45:40 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "unknown";
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	*this = copy;
	std::cout << "Animal: Copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& copy)
{
	if (this != &copy)
		this->type = copy.type;
	std::cout << "Animal: Copy assignment operator called" << std::endl;
	return (*this);
}
