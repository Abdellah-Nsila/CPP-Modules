/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:07:35 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/16 10:48:26 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

class SyntaxError : public std::exception
{
	public:
		const char*	what() const throw()
		{
			return "Error";
		}
}

int	RPN(const std::string& exp)
{
	std::stack<int>	container;

	for (size_t i = 0; i < exp.length(); i++)
	{
		if (std::isdigit(exp[i]))
			container.push(static_cast<int>(exp[i]));
		else
			throw SyntaxError();

		if (container.size() == 0)
		{
			if (std::isdigit(exp[i]))
				container.push(static_cast<int>(exp[i]));
			else
				throw SyntaxError();
		}
	}
}

