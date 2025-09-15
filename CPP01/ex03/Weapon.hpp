/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:55:06 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 10:13:38 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP
#define __WEAPON_HPP

# include <iostream>

class Weapon
{
	public:
		Weapon( std::string	type );
		~Weapon( void );
		const std::string&	getType( void ) const;
		void				setType( std::string type );
			
	private:
		std::string	_type;
};

#endif
