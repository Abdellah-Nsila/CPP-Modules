/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:12:07 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/19 18:35:16 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{	
	float	d1;
	float	d2;
	float	d3;

	d1 = (b.getX().toFloat() - a.getX().toFloat()) * (point.getY().toFloat() - a.getY().toFloat())
		- (b.getY().toFloat() - a.getY().toFloat()) * (point.getX().toFloat() - a.getX().toFloat());
	d2 = (c.getX().toFloat() - b.getX().toFloat()) * (point.getY().toFloat() - b.getY().toFloat())
	- (c.getY().toFloat() - b.getY().toFloat()) * (point.getX().toFloat() - b.getX().toFloat());
	d3 = (a.getX().toFloat() - c.getX().toFloat()) * (point.getY().toFloat() - c.getY().toFloat())
	- (a.getY().toFloat() - c.getY().toFloat()) * (point.getX().toFloat() - c.getX().toFloat());

	if ((d1 > 0 && d2 > 0 && d3 > 0)
		|| (d1 < 0 && d2 < 0 && d3 < 0))
		return (true);
	return (false);
}
