/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:09:09 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/14 13:29:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
# ifndef FIXED_H_
# define FIXED_H_

#include <iostream>

class	Fixed
{
	private:
		int					_fixedPoint;
		static int const	_fractionalBits = 8;
	public:
		Fixed();
		Fixed( const Fixed& other );
		~Fixed();
		
		Fixed&	operator=(const Fixed& copy);

		int		getRawBits( void );
		void	setRawBits( int const raw );
};

#endif

