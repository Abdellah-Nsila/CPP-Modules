/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:09:09 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/14 18:26:42 by abnsila          ###   ########.fr       */
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
		int					_fixedPoint;
		static int const	_fractionalBits = 8;
	public:
		Fixed();
		Fixed( const int intValue );
		Fixed( const float floatValue );
		Fixed( const Fixed& copy );
		~Fixed();
		
		Fixed&	operator=(const Fixed& copy);
		friend std::ostream& operator<<(std::ostream& cout, const Fixed& other);

		int		getRawBits( void );
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

#endif
