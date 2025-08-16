/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:37:07 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/16 09:41:35 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap bot1("Alpha");
    ClapTrap bot2("Bravo");
    ClapTrap bot3(bot2);

    bot1.attack("Bravo");
    bot3.takeDamage(5);

    bot3.beRepaired(3);
    bot3.attack("Alpha");

    // Burn through energy
    for (int i = 0; i < 10; i++)
        bot1.attack("Bravo");

    // Try to attack without energy
    bot1.attack("Bravo");

    // Try to repair without energy
    bot1.beRepaired(5);

    return 0;
}

