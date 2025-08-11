/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:55:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/11 11:39:14 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __Human_A_H__
#define __Human_A_H__

# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
	
		HumanA( std::string name, Weapon& weapon );
		~HumanA( void );
		void				attack( void );
		const std::string&	getName( void );
			
	private:
		
		std::string	_name;
		Weapon&		_weapon;

};

#endif
