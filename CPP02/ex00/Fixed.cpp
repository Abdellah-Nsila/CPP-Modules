/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:09:16 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/13 18:27:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using namespace std;

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	this->_fixedPoint = 0;
}

Fixed::Fixed( const Fixed& other)
{
	cout << "Copy constructor called" << endl;
	*this = other;
}

Fixed::~Fixed()
{
	cout << "Destructor called" <<  endl;
}

Fixed&	Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fixedPoint = copy._fixedPoint; 
}

int	Fixed::getRawBits( void )
{
	cout << "getRawBits member function called" << endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits( int const raw )
{
	cout << "setRawBits member function called" << endl;
	this->_fixedPoint = raw;
}
