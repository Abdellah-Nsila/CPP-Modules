/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:47:39 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/29 19:19:34 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AbstractAnimal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete	this->brain;
	std::cout << "Dog: Destructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : AbstractAnimal()
{
	this->brain = new Brain(*(copy.brain));
	this->type = copy.type;
	std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		AbstractAnimal::operator=(copy);
		delete	this->brain;
		this->type = copy.type;
		this->brain = new Brain(*(copy.brain));
	}
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}
