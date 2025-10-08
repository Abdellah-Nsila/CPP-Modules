/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:47:39 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/08 17:40:50 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete	this->_brain;
	std::cout << "Dog: Destructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	this->_brain = new Brain(*(copy._brain));
	std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete	this->_brain;
		this->_brain = new Brain(*(copy._brain));
	}
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}

const std::string	Dog::getIdea(int idx) const
{
	return (this->_brain->getIdea(idx));
}

void	Dog::setIdea(int idx, std::string& idea)
{
	this->_brain->setIdea(idx, idea);
}
