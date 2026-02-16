/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:07:35 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/16 12:35:07 by abnsila          ###   ########.fr       */
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
};

operatorType	getOperatorType(char op)
{
	if (op == '+')
		return (PLUS);
	else if (op == '-')
			return (MINUS);
	else if (op == '*')
		return (MULTI);
	else if (op == '/')
		return (DIV);
	else
		return (INVALID);
}

int	operation(int a, int b, char op)
{
	// operatorType type = getOperatorType(op);
	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			break;
	}
}

int	RPN(const std::string& exp)
{
	std::stack<int>	container;
	int	a;
	int	b;
	std::string	operators = "+-*/";

	for (size_t i = 0; i < exp.length(); i++)
	{
		if (std::isdigit(exp[i]))
			container.push(static_cast<int>(exp[i]));
		else
			throw SyntaxError();

		if (container.size() == 0)
		{
			i++;
			if (i < exp.length() && std::isdigit(exp[i]))
				container.push(static_cast<int>(exp[i]));
			else
				throw SyntaxError();
		}
		a = container.top();
		container.pop();
		b = container.top();
		container.pop();

		if (i < exp.length() && operators.find(exp[i]) != std::string::npos)
			container.push(operation(a, b, exp[i]));
		else
			SyntaxError();
	}
	if (container.size() != 1)
		SyntaxError();
	return (container.top());
}

