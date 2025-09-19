/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:18:29 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 16:05:41 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"



// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

string	boolToString(bool flag)
{
	if (flag)
		return ("True");
	return ("False");
}

int	main( void )
{
	// Constrcutor Type
	Fixed	a;
	Fixed	b(42);
	const Fixed	c(13.37f);
	const Fixed	d(Fixed(2004) - b);

	// << Operator and show init value
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	
	// ==, -, Comparison opearators 
	a = c - b;
	std::cout << a << std::endl;
	std::cout << boolToString(a < b) << std::endl;
	std::cout << boolToString(b > c) << std::endl;
	std::cout << boolToString(a <= c) << std::endl;
	std::cout << boolToString(d <= b) << std::endl;
	std::cout << boolToString(a == a) << std::endl;
	std::cout << boolToString(c != d) << std::endl;

	// Arithmetic operators
	std::cout << b - a << std::endl;
	std::cout << b / 2 << std::endl;
	std::cout << c * 2  << std::endl;
	std::cout << d + d << std::endl;

	// Increment/decrement
	std::cout << b << std::endl;
	std::cout << b-- << std::endl;
	std::cout << --b << std::endl;
	
	// Max, Min
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::max(c, d) << std::endl;
}
