/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:09:16 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/13 18:12:07 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using namespace std;

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	this->_fullRawIntegerValue = 0;
}

Fixed::Fixed( const int integer )
{
	cout << "Int constructor called" << endl;
	this->_fullRawIntegerValue = integer << this->_numberOfFractionalBits;
}

Fixed::Fixed( const float floatPointNumber )
{
	cout << "Float constructor called" << endl;
	this->_fullRawIntegerValue = roundf(floatPointNumber * (1 << this->_numberOfFractionalBits));
	// this->_fullRawIntegerValue = roundf(floatPointNumber * 256);
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

int	Fixed::getRawBits( void )
{
	cout << "getRawBits member function called" << endl;
	return (this->_fullRawIntegerValue);
}

void	Fixed::setRawBits( int const raw )
{
	cout << "setRawBits member function called" << endl;
	this->_fullRawIntegerValue = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fullRawIntegerValue / (1 << this->_numberOfFractionalBits));
}

int		Fixed::toInt( void ) const
{
	return (this->_fullRawIntegerValue >> this->_numberOfFractionalBits);
}

ostream&	operator<<(ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return (os);
}

Fixed&	Fixed::operator=(const Fixed& other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		if (this != &other)
			this->_fullRawIntegerValue = other._fullRawIntegerValue; 
		return (*this);
	}
