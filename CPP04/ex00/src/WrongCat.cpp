/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:47:44 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/08 16:17:04 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& copy)
{
	if (this != &copy)
	{
		WrongAnimal::operator=(copy);	
	}
	std::cout << "WrongCat: Copy assignment operator called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Meoooooow!" << std::endl;
}
