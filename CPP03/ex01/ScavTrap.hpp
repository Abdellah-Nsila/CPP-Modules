/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 09:44:37 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 15:31:37 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP
#define ScavTrap_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	protected:
	
		ScavTrap();
		
	public:
	
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap& copy);
		~ScavTrap();

		ScavTrap&	operator=(const ScavTrap& copy);

		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif
