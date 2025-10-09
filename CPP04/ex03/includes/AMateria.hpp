/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:35 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/09 16:03:18 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "string.h"
#include "ICharacter.hpp"
#include "MateriaTracker.hpp"

# define MATERIAS_SLOTS 4

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(const AMateria& copy);
		virtual ~AMateria();
		AMateria&			operator=(const AMateria& copy);
		std::string const	&getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};
