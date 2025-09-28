/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:14:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/27 18:16:34 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat& copy);
		~Cat();
		Cat&	operator=(const Cat& copy);
		const std::string	getType() const;
		void	makeSound() const;
};
