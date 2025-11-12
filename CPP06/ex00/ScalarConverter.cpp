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
#include <sstream>
#include <cstdlib>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

void	convertToChar(std::string s)
{
	std::stringstream	ss(s);
	int					n_int;

	ss >> n_int ;
	std::cout << "Int: " << n_int << ", \"" << s << "\"" << std::endl;
	if (n_int >= 32 && n_int <= 126)
		std::cout << static_cast<char>(n_int) << std::endl;
	else if (s != "0" && s != "-0" && n_int == 0)
		std::cout << "impossible" << std::endl;
	else if (n_int <= 255)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void	convertToInt(std::string s)
{
	std::stringstream	ss(s);
	int	n_int;

	ss >> n_int;

	
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

bool	isChar(std::string s)
{
	if (s.length() == 1 && !isdigit(s[0]))
	{
		return (true);
	}
	return (false);
}

bool	isInt(std::string s)
{
	int		value;
	char*	endPtr;

	endPtr = NULL;
	value = strtol(s.c_str(), &endPtr, 10);
	if (*endPtr != '\0')
	{
		std::cout << "Not int: " << "\"" << endPtr << "\"" << std::endl;
		return (false);
	}
	return (true);
}

bool	isFloat(std::string s)
{
	float		value;
	char*		endPtr;
	std::string	rest;

	endPtr = NULL;
	value = strtof(s.c_str(), &endPtr);
	if (endPtr == NULL)
	{
		std::cout << "Not float: " << "\"" << endPtr << "\"" << std::endl;
		return (false); //Dosen't contain "f" at the end (42.0)
	}
	rest = endPtr;
	//TODO: More test accept only (n.nf)
	if (rest != "f" || s.find('.', 1) == std::string::npos)
	{
		std::cout << "Not float: " << "\"" << endPtr << "\"" << std::endl;
		return (false); //Dosen't contain exaclty ".f" or "f" at the end (42.0ffff, 42f)
	}
	return (true);
}

bool	isDouble(std::string s)
{
	double		value;
	char*		endPtr;

	if (s == "0.0" || s == "-0.0")
		return (true);
	value = strtod(s.c_str(), &endPtr);
	if (endPtr)
		return (false); //Contain other stuff at the end (42.0gfd)
	if (value != 0.0 && endPtr == NULL)
		return (true);
	return (false);
}

void	detectType(std::string s)
{
	std::cout << "\"" << s << "\"" << std::endl;
	if (isChar(s))
		std::cout << "isChar: " << s << std::endl;
	if (isInt(s))
		std::cout << "isInt: " << s << std::endl;
	if (isFloat(s))
		std::cout << "isFloat: " << s << std::endl;
	if (isDouble(s))
		std::cout << "isDouble: " << s << std::endl;
}

void	ScalarConverter::convert(std::string& s)
{
	detectType(s);
	// convertToChar(s);
	// convertToInt(s);
	// convertToFloat(s);
	// convertToDouble(s);
}
