/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:09:09 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 15:33:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					_fixedPoint;
		static int const	_fractionalBits = 8;
	public:
		Fixed();
		Fixed( const Fixed& copy );
		Fixed&	operator=(const Fixed& copy);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
