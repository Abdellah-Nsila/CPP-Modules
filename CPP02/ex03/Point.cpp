/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:12:31 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/19 18:21:25 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point( const Point& copy ) : _x(copy._x), _y(copy._y) {}

Point&	Point::operator=( const Point& copy )
{
	(void)copy;
	std::cout << "You can't copy constant attributes!!" << std::endl;
	return (*this);
}

Point::~Point() {}

const Fixed&	Point::getX() const
{
	return (this->_x);
}

const Fixed&	Point::getY() const
{
	return (this->_y);
}
