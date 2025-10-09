/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaTracker.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:03:58 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/09 16:21:51 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "string"
#include "AMateria.hpp"

#define MAX_MATERIAS 1024

class MateriaTracker
{
	private:
		static AMateria	*_materias[MAX_MATERIAS];
		static int		_count;

	public:
		MateriaTracker();
		~MateriaTracker();
		MateriaTracker(const MateriaTracker& copy);
		MateriaTracker&	operator=(const MateriaTracker& copy);
		static void		trackMateria(AMateria *m);
		static void		deleteMateria(AMateria *ptr);
		static void			clean();
};
