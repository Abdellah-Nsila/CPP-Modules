/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:12:35 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/19 18:33:15 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef POINT_HPP
#define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point();
	Point( const float x, const float y );
	Point( const Point& copy );
	~Point();

	Point&	operator=(const Point& copy);

	const Fixed&	getX() const;
	const Fixed&	getY() const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
