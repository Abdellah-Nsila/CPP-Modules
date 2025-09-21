/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:37:12 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/20 10:00:58 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPPHPP
# define CLAP_TRAP_HPPHPP

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string _name;
		int         _hitPoints;
		int         _energyPoints;
		int         _attackDamage;
		
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap& copy);
		~ClapTrap();

		ClapTrap&	operator=(const ClapTrap& copy);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
