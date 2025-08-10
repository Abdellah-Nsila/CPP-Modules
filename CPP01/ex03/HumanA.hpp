/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:55:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/09 18:04:03 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMAIN_A_H__
#define __HUMAIN_A_H__

# include <iostream>
# include "Weapon.hpp"

class HumainA
{
	public:
	
		HumainA( void );
		HumainA( std::string type, Weapon weapon );
		~HumainA( void );
		void	attack( void );
			
	private:
		
		std::string	_name;
		Weapon		weapon;
		
};

#endif
