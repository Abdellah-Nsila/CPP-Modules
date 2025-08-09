/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:05:08 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/09 14:44:54 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie( std::string	name );
		~Zombie( void );
		void	announce( void );
			
	private:
		
		std::string	_name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
