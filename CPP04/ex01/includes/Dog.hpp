/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:14:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/08 17:40:58 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog(const Dog& copy);
		~Dog();
		Dog&	operator=(const Dog& copy);
		void	makeSound() const;
		const std::string	getIdea(int idx) const;
		void				setIdea(int idx, std::string& idea);
};
