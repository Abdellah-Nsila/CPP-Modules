/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:31:27 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/14 08:48:58 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename IT>
void	displaySpan(IT begin, IT end)
{
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		begin++;
	}
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

int main()
{
	// Test addNumber manualy + addnumber from an array
	try
	{
		Span sp = Span(10);
		sp.addNumber(1337);
		sp.addNumber(13);
		sp.addNumber(37);
		sp.addNumber(12);
		sp.addNumber(101);
		
		int arr[5] = {2, 42, 5, 6, 99};
		sp.addNumber(arr, arr + 5);
		std::cout << "===================== Span Items =====================" << std::endl;
		displaySpan(sp.begin(), sp.end());
		std::cout << "=====================  Shortest/Longest Span =====================" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test addNumber from a vector
	try
	{		
		Span sp(100000);

		std::vector<int> vec;
		for (size_t i = 0; i < 100000; i++)
			vec.push_back(i);
		sp.addNumber(vec.begin(), vec.end());
		// std::cout << "===================== Span Items =====================" << std::endl;
		// displaySpan(sp.begin(), sp.end());
		std::cout << "=====================  Shortest/Longest Span =====================" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test Span Full
	try
	{		
		Span sp(10);

		std::vector<int> vec;
		for (size_t i = 0; i < 11; i++)
			vec.push_back(i);
		sp.addNumber(vec.begin(), vec.end());
		std::cout << "===================== Span Items =====================" << std::endl;
		displaySpan(sp.begin(), sp.end());
		std::cout << "=====================  Shortest/Longest Span =====================" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Not enougth number
	try
	{
		Span sp = Span(2);
		
		sp.addNumber(42);
		std::cout << "===================== Span Items =====================" << std::endl;
		displaySpan(sp.begin(), sp.end());
		std::cout << "=====================  Shortest/Longest Span =====================" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
