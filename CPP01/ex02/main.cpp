/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:27:08 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/09 15:46:00 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	// The memory address of the string variable.
	std::cout << &string << std::endl;
	// The memory address held by stringPTR.
	std::cout << stringPTR << std::endl;
	// The memory address held by stringREF.
	std::cout << &stringREF << std::endl;

	// The value of the string variable.
	std::cout << string << std::endl;
	// The value pointed to by stringPTR.
	std::cout << *stringPTR << std::endl;
	// The value pointed to by stringREF.
	std::cout << stringREF << std::endl;
}


// Key Differences Summarized:
//? Feature
// Pointer
// Reference

//? Declaration
// * operator
// & operator

//? Re-assignment
// Can be re-assigned
// Cannot be re-assigned after initialization

//? Nullability
// Can be nullptr
// Cannot be nullptr

//? Arithmetic
// Pointer arithmetic is possible
// No direct reference arithmetic

//? Dereferencing
// Explicit (using *)
// Implicit

// ?Memory Location
// Has its own memory address and size
// Shares the memory address of the aliased variable

// In essence, references provide a safer and more convenient way to create aliases for variables and are often preferred for passing parameters by reference to functions.
// Pointers offer more flexibility, particularly for dynamic memory management and low-level memory manipulation, 
// but come with the responsibility of handling null values and memory deallocation.
