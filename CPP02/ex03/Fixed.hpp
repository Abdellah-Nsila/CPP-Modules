/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:09:09 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/19 18:32:33 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{

	private:
		int					_fixedPoint;
		static int const	_fractionalBits = 8;

	public:
		Fixed();
		Fixed( const int intValue );
		Fixed( const float floatValue );
		Fixed( const Fixed& copy );
		~Fixed();
		
		Fixed&	operator=(const Fixed& copy);
		bool	operator>(const Fixed& toComp) const;
		bool	operator<(const Fixed& toComp) const;
		bool	operator>=(const Fixed& toComp) const;
		bool	operator<=(const Fixed& toComp) const;
		bool	operator==(const Fixed& toComp) const;
		bool	operator!=(const Fixed& toComp) const;
		Fixed	operator+(const Fixed& toAdd) const;
		Fixed	operator-(const Fixed& toSub) const;
		Fixed	operator*(const Fixed& toMul) const;
		Fixed	operator/(const Fixed& divBy) const;
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		static 			Fixed&		min(Fixed& f1, Fixed& f2);
		static	const	Fixed&		min(const Fixed& f1, const Fixed& f2);
		static 			Fixed&		max(Fixed& f1, Fixed& f2);
		static	const	Fixed&		max(const Fixed& f1, const Fixed& f2);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& cout, const Fixed& other);

#endif
