/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:14:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/29 19:19:34 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Cat: public AbstractAnimal
{
	private:
		Brain	*brain;

	public:
		Cat();
		Cat(const Cat& copy);
		~Cat();
		Cat&	operator=(const Cat& copy);
		void	makeSound() const;
};
