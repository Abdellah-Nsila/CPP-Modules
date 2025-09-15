/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:55:52 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 10:17:44 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __Human_B_HPP
#define __Human_B_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanB
{
	public:
	
		HumanB( std::string name );
		~HumanB( void );
		void				attack( void );
		const std::string&	getName( void ) const;
		const Weapon*		getWeapon( void ) const;
		void				setWeapon(Weapon& weapon);
			
	private:
		
		std::string	_name;
		Weapon*		_weapon;
		
};

#endif
