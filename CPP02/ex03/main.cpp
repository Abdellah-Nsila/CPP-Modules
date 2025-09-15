/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:18:29 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 11:21:21 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"



string	boolToString(bool flag)
{
	if (flag)
		return ("True");
	return ("False");
}

int main( void )
{
	bool isInside;
	Point a(0.0f, 0.0f);
	Point b(1.0f, 7.0f);
	Point c(10.0f, 1.0f);

	Point point1(2.75f, 5.5f);
	Point point2(10.0f, 2.5f);
	
	isInside = bsp(a, b, c, point1);
	cout << boolToString(isInside) << endl;

	isInside = bsp(a, b, c, point2);
	cout << boolToString(isInside) << endl;

	return 0;
}
