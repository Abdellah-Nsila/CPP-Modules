/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:16:17 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/17 10:55:55 by abnsila          ###   ########.fr       */
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

int	operation(std::stack<int>& myStack, char op)
{
	int	b = myStack.top();
	myStack.pop();
	int	a = myStack.top();
	myStack.pop();

	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
		{
			if (b == 0)
        		throw SyntaxError();
			return a / b;
		}
		default:
			throw SyntaxError();
	}
}

int	RPN(const std::string& exp)
{
	std::stringstream	ss(exp);
	std::string			token;
	std::stack<int>		myStack;
	std::string			operators = "+-*/";

	while (ss >> token)
	{
		if (token.length() != 1)
			throw SyntaxError();

		if (std::isdigit(token[0]))
		{
			myStack.push(token[0] - '0');
		}
		else if ((operators.find(token[0]) != std::string::npos) && myStack.size() >= 2)
			myStack.push(operation(myStack, token[0]));
		else
			throw SyntaxError();
	}
	if (myStack.size() != 1)
		throw SyntaxError();
	return myStack.top();
}
