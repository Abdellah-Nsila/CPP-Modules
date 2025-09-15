/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:55:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 10:12:31 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __Human_A_HPP
#define __Human_A_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA( void );
		void				attack( void );
		const std::string&	getName( void ) const;
			
	private:
		std::string	_name;
		Weapon&		_weapon;

};

#endif
