/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:37:07 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/21 16:04:45 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
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
	FragTrap A("Beta");
	A.attack("Enemy1");
	A.highFivesGuys();
    FragTrap C("Charlie");
	FragTrap B(C);
    B.takeDamage(100);
    B.takeDamage(10);
}
