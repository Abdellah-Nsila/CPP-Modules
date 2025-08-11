/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:56:06 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/11 11:53:06 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

int main()
{
	Weapon club1 = Weapon("crude spiked club1");
	HumanA bob("Bob", club1);
	bob.attack();
	club1.setType("some other type of club1");
	bob.attack();

	Weapon club2 = Weapon("crude spiked club2");
	HumanB jim("Jim");
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("some other type of club2");
	jim.attack();

	return 0;
}


// In C++, all members are initialized before the constructor body runs.

// For normal members (like std::string _name), if you don’t initialize them in the initializer list, the compiler will:

//     Call their default constructor (empty string, in this case)

//     Then assign the value inside the constructor body → extra work.

// For references (Weapon& _weapon) and const members, you must use the initializer list because:

//     They have to be initialized immediately, they cannot be reassigned later.

//     A reference can only be bound once — so = weapon; in the body is not possible.
