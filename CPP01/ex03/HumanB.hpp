/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:55:52 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/11 11:49:31 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __Human_B_H__
#define __Human_B_H__

# include <iostream>
# include "Weapon.hpp"
# include "optional"

class	HumanB
{
	public:
	
		HumanB( std::string name );
		~HumanB( void );
		void				attack( void );
		const std::string&	getName( void );
		const Weapon*		getWeapon( void );
		void				setWeapon(Weapon& weapon);
			
	private:
		
		std::string	_name;
		Weapon*		_weapon;
		
};

#endif
