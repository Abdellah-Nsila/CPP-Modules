/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:38:58 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/09 22:22:55 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

void	convertToChar(std::string s)
{
	if (s.length() != 1)
	{
		std::cout << "impossible" << std::endl;	
		return ;
	}
	if (s[0] >= 32 && s[0] <= 126)
		std::cout << static_cast<char>(s[0]) << std::endl;	
	else
		std::cout << "Non displayable" << std::endl; 
}

void	convertToInt(std::string s)
{
	(void)s;
	
}

void	convertToFloat(std::string s)
{
	(void)s;
	// if ()
	// {
		
	// }
}

void	convertToDouble(std::string s)
{
	(void)s;
	// if ()
	// {
		
	// }
}


void	ScalarConverter::convert(std::string& s)
{
	convertToChar(s);
	convertToInt(s);
	convertToFloat(s);
	convertToDouble(s);
}
