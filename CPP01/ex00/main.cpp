/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:31:24 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/09 14:51:34 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie* z = newZombie("Stev");
	
	z->announce();
	delete z;
	randomChump("Alex");
}


//! The point of this exercise

// The exercise is making you think about object lifetime and where objects are stored:

//     Stack allocation

//         Created inside a function as a normal local variable (Zombie z("Foo");)

//         Automatically destroyed when the function ends.

//         No manual cleanup needed.

//         Good for short-lived objects.

//     Heap allocation

//         Created with new (Zombie* z = new Zombie("Foo");)

//         Lives until you explicitly delete it.

//         Lets you return it from functions and keep it after the function ends.

//         Must manually manage memory to avoid leaks.
