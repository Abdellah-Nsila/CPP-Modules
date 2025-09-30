/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:47:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/29 19:26:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::~Cat()
{
	delete	this->brain;
	std::cout << "Cat: Destructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : AAnimal()
{
	this->brain = new Brain(*(copy.brain));
	this->type = copy.type;
	std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& copy)
{
	if (this != &copy)
	{
		AAnimal::operator=(copy);
		delete	this->brain;
		this->type = copy.type;
		this->brain = new Brain(*(copy.brain));
	}
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meoooooow!" << std::endl;
}
