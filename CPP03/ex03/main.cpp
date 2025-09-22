/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:37:07 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/22 11:38:52 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{

	// ============================== ClapTrap Test ==============================
    ClapTrap bot1("Alpha");
    ClapTrap bot2("Bravo");
    ClapTrap bot3(bot2);

    bot1.attack("Bravo");
    bot3.takeDamage(5);
    bot3.beRepaired(3);
    bot3.attack("Alpha");
    for (int i = 0; i < 10; i++)
        bot1.attack("Bravo");
    bot1.attack("Bravo");
    bot1.beRepaired(5);


    // ============================== ScavTrap Test ==============================
    ScavTrap scav("Guardian");

    scav.attack("intruder");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    std::cout << "----- Copy & assignment tests -----" << std::endl;
    ScavTrap scav2(scav);
    ScavTrap scav3("temp");
    scav3 = scav;

	// ============================== FragTrap Test ==============================
	FragTrap F1("Beta");
	F1.attack("Enemy1");
	F1.highFivesGuys();
    FragTrap F2("Charlie");
	FragTrap F3(F2);
    F3.takeDamage(100);
    F3.takeDamage(10);
	
	// ============================== DiamondTrap Test ==============================

	DiamondTrap A;
	DiamondTrap B("B");
	DiamondTrap C = B;
	A = C;

	C.highFivesGuys();

	C.attack("A");

	A.whoAmI();

	return (0);
}
