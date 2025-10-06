/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:25:15 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/06 15:33:55 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character : ICharacter
{
	private:
		std::string	_name;
		AMateria	*_materias[4];
		AMateria	*_dropped_materias[4];
	public:
		Character();
		Character(std::string name);
		Character(const Character &copy);
		~Character();
		Character&			operator=(const Character& copy);
		std::string const	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};
