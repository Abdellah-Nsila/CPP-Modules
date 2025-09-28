/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:47:39 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/27 18:00:45 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
}

Dog::Dog(const Dog& copy)
{
	*this = copy;
	std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& copy)
{
	if (this != &copy)
		this->type = copy.type;
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	return (*this);
}

const std::string	Dog::getType() const
{
	return (this->type);
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}
