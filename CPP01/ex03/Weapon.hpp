/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:55:06 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/11 11:21:48 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

# include <iostream>

class Weapon
{
	public:
    
		Weapon( std::string	type );
		~Weapon( void );
		const std::string&	getType( void );
		void				setType( std::string type );
			
	private:
		
		std::string	_type;
};

#endif

