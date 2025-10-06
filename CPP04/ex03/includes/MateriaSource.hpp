/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:36:41 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/06 17:17:01 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "string"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materias[MATERIAS_SLOTS];

	public:
		MateriaSource();
		~MateriaSource();
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const& type);
};
