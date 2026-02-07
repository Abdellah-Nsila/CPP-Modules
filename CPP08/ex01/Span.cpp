/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:39:08 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/07 10:36:52 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _capacity(0)
{
}

Span::Span(unsigned int N) : _capacity(N)
{
	this->_container.reserve(N);
}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span&	Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		this->_capacity = copy._capacity;
		this->_container = copy._container;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int number)
{
	if (this->_container.size() < this->_capacity)
		this->_container.push_back(number);
	else
		throw SpanIsFull();
}

const char*	Span::SpanIsFull::what() const throw()
{
	return "Span is full.";
}

const char*	Span::UnderTwoNumbers::what() const throw()
{
	return "Container must have at least two elements to find a span.";
}

int		Span::shortestSpan()
{
	int	minSpan;
	int	currentSpan;

	if (this->_container.size() < 2)
		throw UnderTwoNumbers();
	
	std::vector<int>	sortedContainer(this->_container);
	std::sort(sortedContainer.begin(), sortedContainer.end());
	minSpan = sortedContainer[this->_container.size() - 1];

	for (unsigned int i = 0; i < this->_container.size() - 1; i++)
	{
		currentSpan = sortedContainer[i + 1] - sortedContainer[i];
		if (currentSpan < minSpan)
		minSpan = currentSpan;
	}
	return (minSpan);
}

int		Span::longestSpan()
{
	if (this->_container.size() < 2)
		throw UnderTwoNumbers();
	
	std::vector<int>	sortedContainer(this->_container);
	std::sort(sortedContainer.begin(), sortedContainer.end());

	std::vector<int>::iterator	min_it = std::min_element(this->_container.begin(), this->_container.end());
	std::vector<int>::iterator	max_it = std::max_element(this->_container.begin(), this->_container.end());

	return (*max_it - *min_it);
}
