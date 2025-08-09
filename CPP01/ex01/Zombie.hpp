/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:05:08 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/09 15:12:49 by abnsila          ###   ########.fr       */
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
		Zombie( void );
		Zombie( std::string	name );
		~Zombie( void );
		void	announce( void );
		void	setName( std::string name );
			
	private:
		
		std::string	_name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );
Zombie*	zombieHorde( int N, std::string name );

#endif
