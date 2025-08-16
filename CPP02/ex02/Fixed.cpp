/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:09:16 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/16 09:28:03 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using namespace std;

Fixed::Fixed()
{
	// cout << "Default constructor called" << endl;
	this->_fixedPoint = 0;
}

Fixed::Fixed( const int intValue )
{
	// cout << "Int constructor called" << endl;
	this->_fixedPoint = intValue << this->_fractionalBits;
}

Fixed::Fixed( const float floatValue )
{
	// cout << "Float constructor called" << endl;
	this->_fixedPoint = roundf(floatValue * (1 << this->_fractionalBits));
	// this->_fixedPoint = roundf(floatValue * 256); 2^8 (in base 2) is like 10^8 (in base 10)
}

Fixed::Fixed( const Fixed& copy)
{
	// cout << "Copy constructor called" << endl;
	if (this != &copy)
		this->_fixedPoint = copy._fixedPoint; 
}

Fixed::~Fixed()
{
	// cout << "Destructor called" <<  endl;
}

// An overload of the insertion («) operator
ostream&	operator<<(ostream& cout, const Fixed& other)
{
	cout << other.toFloat();
	return (cout);
}

// Copy assignment operator overload.
Fixed&	Fixed::operator=(const Fixed& copy)
{
	// cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fixedPoint = copy._fixedPoint; 
	return (*this);
}

// The 6 comparison operators: >, <, >=, <=, == and !=.
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

// The 4 arithmetic operators: +, -, *, and /.
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
	// resultObj._fixedPoint = roundf((this->toFloat() * toMul.toFloat()) * (1 << this->_fractionalBits));
	return (resultObj);
}

Fixed	Fixed::operator/(const Fixed& divBy) const
{
	Fixed	resultObj;

	resultObj._fixedPoint = ((long)this->_fixedPoint << this->_fractionalBits) / divBy._fixedPoint;
	// resultObj._fixedPoint = roundf((this->toFloat() / divBy.toFloat()) * (1 << this->_fractionalBits));
	return (resultObj);
}

// The 4 increment/decrement
// Prefix increment
Fixed&	Fixed::operator++()
{
	this->_fixedPoint++;
	return (*this);
}

// Postfix increment
Fixed	Fixed::operator++(int)
{
	Fixed	oldObj(*this);
	
	this->_fixedPoint++;
	return (oldObj);
}

// Prefix decrement
Fixed&	Fixed::operator--()
{
	this->_fixedPoint--;
	return (*this);
}

// Postfix decrement
Fixed	Fixed::operator--(int)
{
	Fixed	oldObj(*this);
	
	this->_fixedPoint--;
	return (oldObj);
}

// Static member function min / max
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

int	Fixed::getRawBits( void )
{
	// cout << "getRawBits member function called" << endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits( int const raw )
{
	// cout << "setRawBits member function called" << endl;
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
