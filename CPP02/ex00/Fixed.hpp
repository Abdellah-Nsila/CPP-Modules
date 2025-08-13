/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:09:09 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/13 11:33:32 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
# ifndef FIXED_H_
# define FIXED_H_

#include <iostream>

class	Fixed
{
	private:
		int					_fullRawIntegerValue;
		static int const	_numberOfFractionalBits = 8;
	public:
		Fixed();
		Fixed( const Fixed& other );
		Fixed& operator=(const Fixed& other)
		{
			std::cout << "Copy assignment operator called" << std::endl;
			if (this != &other)
				this->_fullRawIntegerValue = other._fullRawIntegerValue; 
			return (*this);
		}
		~Fixed();

		int		getRawBits( void );
		void	setRawBits( int const raw );
};

#endif

