/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:10:59 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/28 16:13:28 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	*this = copy;
	std::cout << "Brain: Copy constructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& copy)
{
	//TODO: Correct the array copy
	if (this != &copy)
		this->ideas = copy.ideas;
	std::cout << "Brain: Copy assignment operator called" << std::endl;
	return (*this);
}
