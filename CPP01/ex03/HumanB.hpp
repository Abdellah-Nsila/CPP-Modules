/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:55:52 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/09 18:04:39 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMAIN_B_H__
#define __HUMAIN_B_H__

# include <iostream>
# include "Weapon.hpp"

class HumainB
{
	public:
	
		HumainB( void );
		HumainB( std::string type, Weapon weapon );
		~HumainB( void );
		void	attack( void );
			
	private:
		
		std::string	_name;
		Weapon		weapon;
		
};

#endif
