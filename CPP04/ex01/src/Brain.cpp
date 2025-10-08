/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:10:59 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/08 17:35:50 by abnsila          ###   ########.fr       */
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
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	std::cout << "Brain: Copy assignment operator called" << std::endl;
	return (*this);
}

const std::string	Brain::getIdea(int idx) const
{
	if (idx >= 0 && idx < 100)
		return (this->ideas[idx]);
	else
	{	
		std::cout << "Index: " << idx << " out of range" << std::endl;
		return ("");
	}
}

void	Brain::setIdea(int idx, std::string& idea)
{
	if (idx >= 0 && idx < 100)
		this->ideas[idx] = idea;
	else
		std::cout << "Index: " << idx << " out of range" << std::endl;
}
