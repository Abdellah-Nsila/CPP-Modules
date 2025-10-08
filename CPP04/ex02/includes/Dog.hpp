/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:14:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/08 18:19:07 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
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
