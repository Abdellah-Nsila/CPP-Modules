/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstarctAnimal.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:13:49 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/29 19:19:34 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "string"

class AbstractAnimal
{
	protected:
		std::string type;

	public:
		AbstractAnimal();
		AbstractAnimal(const AbstractAnimal& copy);
		virtual ~AbstractAnimal();
		AbstractAnimal&	operator=(const AbstractAnimal& copy);
		const std::string	getType() const;
		virtual void		makeSound() const = 0;
};
