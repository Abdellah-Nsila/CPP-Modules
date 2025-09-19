/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:56:20 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 15:31:37 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class DiamondTrap: public ClapTrap
{
	protected:
	
		DiamondTrap();
		
	public:
	
		DiamondTrap(std::string _name);
		DiamondTrap(const DiamondTrap& copy);
		~DiamondTrap();

		DiamondTrap&	operator=(const DiamondTrap& copy);

		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif
