/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:31:27 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/03 15:47:16 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#define MAX_SIZE 5

int	main()
{
	Span	s(MAX_SIZE);
	
	s.addNumber(1);
	s.addNumber(5);
	s.addNumber(7);
	s.addNumber(6);
	s.addNumber(60);
	s.addNumber(99);
	
	Span	s1(s);
	
	Span	s2;
	s2 = s;

	s.display();	
	s1.display();	
	s2.display();	
}
