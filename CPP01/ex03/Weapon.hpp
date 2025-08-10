/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:55:06 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/09 18:02:27 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

# include <iostream>

class Weapon
{
	public:
    
		Weapon( void );
		Weapon( std::string	type );
		~Weapon( void );
		void	getType( void ) const;
		void	setType( std::string type );
			
	private:
		
		std::string	_type;
};

#endif
