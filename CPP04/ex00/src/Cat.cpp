/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:47:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/08 16:16:14 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);	
	}
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meoooooow!" << std::endl;
}
