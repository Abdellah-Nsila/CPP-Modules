/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:36:25 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/06 16:36:28 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		
	public:
		Ice();
		Ice(const Ice& copy);
		~Ice();
		Ice&		operator=(const Ice& copy);
		AMateria*	clone() const;
		void		use(ICharacter& target);
};
