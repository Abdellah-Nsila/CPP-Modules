/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:06:57 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/04 09:08:48 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
	// Initialization
	Array<int>	arr1;
	Array<int>	arr2(5);

	std::cout << arr1.size() << std::endl;
	std::cout << arr2.size() << std::endl;

	// Exception and [] operator
	try
	{
		std::cout << arr1[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << arr2[0] << std::endl;

	// Exception and [] operator
	try
	{
		std::cout << arr2[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
