/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:36:11 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/06 18:43:31 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_materias[MATERIAS_SLOTS];
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
