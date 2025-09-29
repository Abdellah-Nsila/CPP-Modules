/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:14:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/27 18:26:53 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "string"

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal& copy);
		virtual ~Animal();
		Animal&	operator=(const Animal& copy);
		const std::string	getType() const;
		virtual void		makeSound() const;
};
