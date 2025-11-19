/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:52:06 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/19 16:07:45 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

int	main()
{
	int 		i1, i2;	
	double		d1, d2;
	std::string	s1, s2;

	i1 = 5;
	i2 = 10;

	d1 = 7.5;
	d2 = 2.25;

	s1 = "Hello";
	s2 = "World";

	std::cout << "=========================== Before ===========================" << std::endl;
	std::cout << "int 1: " << i1 << ", int 2: " << i2 << std::endl;
	std::cout << "double 1: " << d1 << ", double 2: " << d2 << std::endl;
	std::cout << "string 1: " << s1 << ", string 2: " << s2 << std::endl;
	
	swap(i1, i2);
	swap(d1, d2);
	swap(s1, s2);
	
	std::cout << "=========================== Swap ===========================" << std::endl;
	std::cout << "int 1: " << i1 << ", int 2: " << i2 << std::endl;
	std::cout << "double 1: " << d1 << ", double 2: " << d2 << std::endl;
	std::cout << "string 1: " << s1 << ", string 2: " << s2 << std::endl;
	
	std::cout << "=========================== Min ===========================" << std::endl;
	std::cout << "Min: " << min(i1, i2) << std::endl;
	std::cout << "Min: " << min(d1, d2) << std::endl;
	std::cout << "Min: " << min(s1, s2) << std::endl;
	
	std::cout << "=========================== Max ===========================" << std::endl;
	std::cout << "Max: " << max(i1, i2) << std::endl;
	std::cout << "Max: " << max(d1, d2) << std::endl;
	// std::cout << "Max: " << max(s1, s2) << std::endl;
	

}