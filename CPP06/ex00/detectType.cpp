/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:04:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/18 09:09:27 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "detectType.hpp"

bool	isChar(std::string s)
{
	return (s.length() == 1 && !isdigit(s[0]));
}

bool	isInt(std::string s)
{
	std::stringstream	ss(s);
	int		value;
	char	leftOver;

	ss >> value;
	if (ss.fail())
		return (false);
	if (ss >> leftOver)
		return (false);
	return (true);
}

bool	isFloat(std::string s)
{
	float	value;
	char	leftOver;

	if (s == "-inff" || s == "+inff" || s == "inff" || s == "nanf")
		return (true);
	if (s[s.length() - 1] != 'f')
		return (false);
	std::stringstream	ss(s.substr(0, s.length() - 1));
	ss >> value;
	if (ss.fail())
		return (false);
	if (ss >> leftOver)
		return (false);
	if (s.find('.') == std::string::npos)
		return (false);
	return (true);
}

bool	isDouble(std::string s)
{
	double	value;
	char	leftOver;
	if (s == "-inf" || s == "+inf" || s == "inf" || s == "nan")
		return (true);
	std::stringstream	ss(s);
	ss >> value;
	if (ss.fail())
		return (false);
	if (ss >> leftOver)
		return (false);
	if (s.find('.') == std::string::npos)
		return (false);
	return (true);
}

literalType	getType(std::string s)
{
	if (isChar(s))
		return (CHAR);
	else if (isInt(s))
			return (INT);
	else if (isFloat(s))
		return (FLOAT);
	else if (isDouble(s))
		return (DOUBLE);
	else
		return (INVALID);
}
