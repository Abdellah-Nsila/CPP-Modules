/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:09:09 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/13 18:14:43 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
# ifndef FIXED_H_
# define FIXED_H_

#include <iostream>
#include <cmath>

class	Fixed
{

	private:
		int					_fullRawIntegerValue;
		static int const	_numberOfFractionalBits = 8;

	public:
		// Constructors / Destructor
		Fixed();
		Fixed( const int integer );
		Fixed( const float floatPointNumber );
		Fixed( const Fixed& other );
		~Fixed();
		
		// An overload of the insertion («) operator
		friend	std::ostream& operator<<(std::ostream& os, const Fixed& other);
		// Copy assignment operator overload.
		Fixed&	operator=(const Fixed& other);
		// The 6 comparison operators: >, <, >=, <=, == and !=.
		bool	operator>(const Fixed& other);
		bool	operator<(const Fixed& other);
		bool	operator>=(const Fixed& other);
		bool	operator<=(const Fixed& other);
		bool	operator==(const Fixed& other);
		bool	operator!=(const Fixed& other);
		// The 4 arithmetic operators: +, -, *, and /.
		Fixed&	operator+(const Fixed& other);
		Fixed&	operator-(const Fixed& other);
		Fixed&	operator*(const Fixed& other);
		Fixed&	operator/(const Fixed& other);
		// The 4 increment/decrement
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		// Member functions
		int		getRawBits( void );
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

#endif
