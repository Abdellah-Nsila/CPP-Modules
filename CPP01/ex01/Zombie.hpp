/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:05:08 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 09:31:35 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP
#define __ZOMBIE_HPP

# include <iostream>

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

Zombie*	zombieHorde( int N, std::string name );

#endif
