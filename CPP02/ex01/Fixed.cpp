/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:09:16 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/14 13:29:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using namespace std;

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	this->_fixedPoint = 0;
}

Fixed::Fixed( const int intValue )
{
	cout << "Int constructor called" << endl;
	this->_fixedPoint = intValue << this->_fractionalBits;
}

Fixed::Fixed( const float floatValue )
{
	cout << "Float constructor called" << endl;
	this->_fixedPoint = roundf(floatValue * (1 << this->_fractionalBits));
	// this->_fixedPoint = roundf(floatValue * 256);
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

ostream&	operator<<(ostream& cout, const Fixed& other)
{
	cout << other.toFloat();
	return (cout);
}

Fixed&	Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fixedPoint = copy._fixedPoint; 
	return (*this);
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

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixedPoint / (1 << this->_fractionalBits));
}

int		Fixed::toInt( void ) const
{
	return (this->_fixedPoint >> this->_fractionalBits);
}
