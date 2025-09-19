/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:09:16 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/19 17:46:28 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
}

Fixed::Fixed( const int intValue )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = intValue << this->_fractionalBits;
}

Fixed::Fixed( const float floatValue )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(floatValue * (1 << this->_fractionalBits));
}

Fixed::Fixed( const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" <<  std::endl;
}

std::ostream&	operator<<(std::ostream& cout, const Fixed& other)
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

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
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
