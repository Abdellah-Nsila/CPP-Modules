/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:48:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/10/08 18:03:22 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	// ====================== Subject Test ======================
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;
	
	// ====================== My Test ======================
	Animal	*animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	
	for (int i = 0; i < 10; i++)
	{
		animals[i]->getType();
		animals[i]->makeSound();
	}

	for (int i = 0; i < 10; i++)
	{
		delete	animals[i];
	}
	
	// ====================== deep copy Test ======================
	std::string ideas[10] = {"Fetch the ball: 1", "Fetch the ball: 2", "Fetch the ball: 3", "Fetch the ball: 4", "Fetch the ball: 5"
		, "Fetch the ball: 6", "Fetch the ball: 7", "Fetch the ball: 8", "Fetch the ball: 9", "Fetch the ball: 10"};
	Dog *original = new Dog();

	for (int i = 0; i < 10; i++)
	{	
		original->setIdea(i, ideas[i]);
	}
	
	for (int i = 0; i < 10; i++)
	{	
		std::cout << original->getIdea(i) << std::endl;
	}

	Dog *copy = new Dog(*original);
	for (int i = 0; i < 10; i++)
	{	
		std::cout << copy->getIdea(i) << std::endl;
	}

	delete original;
	delete copy;
	
	return 0;
}
