/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:09:16 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/19 18:17:16 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixedPoint = 0;
}

Fixed::Fixed( const int intValue )
{
	this->_fixedPoint = intValue << this->_fractionalBits;
}

Fixed::Fixed( const float floatValue )
{
	this->_fixedPoint = roundf(floatValue * (1 << this->_fractionalBits));
}

Fixed::Fixed( const Fixed& copy)
{
	this->_fixedPoint = copy._fixedPoint; 
}

Fixed::~Fixed() {}

std::ostream&	operator<<(std::ostream& cout, const Fixed& other)
{
	cout << other.toFloat();
	return (cout);
}

Fixed&	Fixed::operator=(const Fixed& copy)
{
	if (this != &copy)
		this->_fixedPoint = copy._fixedPoint; 
	return (*this);
}

bool	Fixed::operator>(const Fixed& toComp) const
{
	return (this->_fixedPoint > toComp._fixedPoint);
}

bool	Fixed::operator<(const Fixed& toComp) const
{
	return (this->_fixedPoint < toComp._fixedPoint);
}

bool	Fixed::operator>=(const Fixed& toComp) const
{
	return (this->_fixedPoint >= toComp._fixedPoint);
}

bool	Fixed::operator<=(const Fixed& toComp) const
{
	return (this->_fixedPoint <= toComp._fixedPoint);
}

bool	Fixed::operator==(const Fixed& toComp) const
{
	return (this->_fixedPoint == toComp._fixedPoint);
}

bool	Fixed::operator!=(const Fixed& toComp) const
{
	return (this->_fixedPoint != toComp._fixedPoint);
}

Fixed	Fixed::operator+(const Fixed& toAdd) const
{
	Fixed	resultObj;

	resultObj._fixedPoint = this->_fixedPoint + toAdd._fixedPoint;
	return (resultObj);
}

Fixed	Fixed::operator-(const Fixed& toSub) const
{
	Fixed	resultObj;

	resultObj._fixedPoint = this->_fixedPoint - toSub._fixedPoint;
	return (resultObj);
}

Fixed	Fixed::operator*(const Fixed& toMul) const
{
	Fixed	resultObj;

	resultObj._fixedPoint = (this->_fixedPoint * toMul._fixedPoint) >> this->_fractionalBits;
	return (resultObj);
}

Fixed	Fixed::operator/(const Fixed& divBy) const
{
	Fixed	resultObj;

	resultObj._fixedPoint = ((long)this->_fixedPoint << this->_fractionalBits) / divBy._fixedPoint;
	return (resultObj);
}

Fixed&	Fixed::operator++()
{
	this->_fixedPoint++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	oldObj(*this);
	
	this->_fixedPoint++;
	return (oldObj);
}

Fixed&	Fixed::operator--()
{
	this->_fixedPoint--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	oldObj(*this);
	
	this->_fixedPoint--;
	return (oldObj);
}

Fixed&		Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed&		Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed&		Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed&		Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_fixedPoint);
}

void	Fixed::setRawBits( int const raw )
{
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
