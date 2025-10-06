/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:36:20 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/06 17:36:04 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		
	public:
		Cure();
		Cure(const Cure& copy);
		~Cure();
		Cure&		operator=(const Cure& copy);
		AMateria*	clone() const;
		void		use(ICharacter& target);
};
