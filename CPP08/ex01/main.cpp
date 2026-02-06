/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:31:27 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/06 19:09:52 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#define MAX_SIZE 5

int main()
{
	srand(time(0));
	try
	{
		Span sp = Span(10);
		sp.addNumber(1337);
		sp.addNumber(13);
		sp.addNumber(37);
		sp.addNumber(12);
		sp.addNumber(101);
		
		int arr[] = {2, 42, 5, 6, 99};
		sp.addNumber(arr, arr + 5);
		sp.display();
		// std::cout << sp.shortestSpan() << std::endl;
		// std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

// int	main()
// {
// 	Span	s(MAX_SIZE);
	
// 	s.addNumber(6);
// 	s.addNumber(60);
// 	s.addNumber(5);
// 	s.addNumber(7);
// 	s.addNumber(1);
// 	s.addNumber(99);
	
// 	Span	s1(s);
	
// 	Span	s2;
// 	s2 = s;

// 	s.display();	
// 	// s1.display();	
// 	// s2.display();
	
	
// 	std::cout << s.shortestSpan() << std::endl;
// 	std::cout << s.longestSpan() << std::endl;
// }
