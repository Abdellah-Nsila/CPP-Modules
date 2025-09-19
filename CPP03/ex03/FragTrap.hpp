/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 12:20:40 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 15:31:37 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	protected:
	
		FragTrap();
		
	public:
	
		FragTrap(std::string _name);
		FragTrap(const FragTrap& copy);
		~FragTrap();

		FragTrap&	operator=(const FragTrap& copy);

		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif
