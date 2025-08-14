/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:18:29 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/14 16:29:54 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using namespace std;

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	cout << a << endl;
// 	cout << ++a << endl;
// 	cout << a << endl;
// 	cout << a++ << endl;
// 	cout << a << endl;
// 	cout << b << endl;
// 	cout << Fixed::max( a, b ) << endl;
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
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	
	// ==, -, Comparison opearators 
	a = c - b;
	cout << a << endl;
	cout << boolToString(a < b) << endl;
	cout << boolToString(b > c) << endl;
	cout << boolToString(a <= c) << endl;
	cout << boolToString(d <= b) << endl;
	cout << boolToString(a == a) << endl;
	cout << boolToString(c != d) << endl;

	// Arithmetic operators
	cout << b - a << endl;
	cout << b / 2 << endl;
	cout << c * 2  << endl;
	cout << d + d << endl;

	// Increment/decrement
	cout << b << endl;
	cout << b-- << endl;
	cout << --b << endl;
	
	// Max, Min
	cout << Fixed::min(a, b) << endl;
	cout << Fixed::min(c, d) << endl;
	cout << Fixed::max(a, b) << endl;
	cout << Fixed::max(c, d) << endl;
}
