/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:37:26 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/06 18:43:42 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria *m1 = src->createMateria("ice");
	me->equip(m1);
	AMateria *m2 = src->createMateria("cure");
	me->equip(m2);
	AMateria *m3 = src->createMateria("ice");
	me->equip(m3);
	AMateria *m4 = src->createMateria("cure");
	me->equip(m4);
	AMateria *m5 = src->createMateria("cure");
	me->equip(m5);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->unequip(0);
	me->use(1, *bob);
	me->unequip(1);
	me->use(2, *bob);
	me->unequip(2);
	me->use(3, *bob);
	me->unequip(3);

	delete m1;
	delete m2;
	delete m3;
	delete m4;
	delete m5;
	
	delete bob;
	delete me;
	delete src;

	return 0;
}
