/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:47:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/08 17:40:32 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::~Cat()
{
	delete	this->_brain;
	std::cout << "Cat: Destructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	this->_brain = new Brain(*(copy._brain));
	std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete	this->_brain;
		this->_brain = new Brain(*(copy._brain));
	}
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meoooooow!" << std::endl;
}

const std::string	Cat::getIdea(int idx) const
{
	return (this->_brain->getIdea(idx));
}

void	Cat::setIdea(int idx, std::string& idea)
{
	this->_brain->setIdea(idx, idea);
}
