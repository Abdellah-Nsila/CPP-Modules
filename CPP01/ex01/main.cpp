/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:31:24 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 09:17:41 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	N = 5;
	Zombie* zh = zombieHorde(N, "Jef");

	for (int i = 0; i < N; i++)
		zh[i].announce();
	delete[] zh;
}


//! The point of this exercise

// Difference between new and new[], and delete vs delete[]:

//     Using new allocates a single object.

//     Using new[] allocates an array of objects.

//     They require matching delete or delete[] respectively.

//     This is fundamental in C++ memory management.

// Why use heap at all?

//     Heap lets you allocate memory dynamically when you don’t know the size at compile time.

//     Stack objects have automatic scope-based lifetime, but limited size and lifetime.

//     This exercise highlights when and why you might choose each.

// Basic class design:

//     Implementing constructors, destructors, member functions.

//     Using private data members with public setters/getters (if needed).

//     Demonstrates encapsulation.

