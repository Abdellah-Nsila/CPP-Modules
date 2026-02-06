/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:39:08 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/06 19:07:39 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Helpers Delete this ?????????????????????????????????
void	displayVector(std::vector<int>	v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}	
}

void	Span::display()
{

	std::cout << "Size: " << this->_container.size() << std::endl;
	std::cout << "Capacity: " << this->_container.capacity() << std::endl;

	for (unsigned int i = 0; i < this->_container.size(); i++)
	{
		std::cout << this->_container[i] << std::endl;
	}	
}

// ======================================================

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

const char*	Span::NoSpanCanBeFound::what() const throw()
{
	return "Container must have at least two elements to find a span.";
}

int		Span::shortestSpan()
{
	int	minSpan;
	int	currentSpan;

	if (this->_container.size() < 2)
		throw NoSpanCanBeFound();
	
	std::vector<int>	sortedContainer(this->_container);
	std::sort(sortedContainer.begin(), sortedContainer.end());
	minSpan = sortedContainer[this->_container.size() - 1];
	std::cout << "=============== shortestSpan ===============" << std::endl;
	displayVector(sortedContainer);

	for (unsigned int i = 0; i < this->_container.size() - 1; i++)
	{
		currentSpan = sortedContainer[i + 1] - sortedContainer[i];
		if (currentSpan < minSpan)
		minSpan = currentSpan;
	}
	std::cout << "=============== ============ ===============" << std::endl;
	return (minSpan);
}

int		Span::longestSpan()
{
	int	maxSpan = 0;
	int	currentSpan;

	if (this->_container.size() < 2)
		throw NoSpanCanBeFound();
	
	std::vector<int>	sortedContainer(this->_container);
	std::sort(sortedContainer.begin(), sortedContainer.end());
	maxSpan = sortedContainer[this->_container.size()- 1] - sortedContainer[0];
	std::cout << "=============== longestSpan ===============" << std::endl;
	displayVector(sortedContainer);

	for (unsigned int i = 0; i < this->_container.size()- 1; i++)
	{
		currentSpan = sortedContainer[i + 1] - sortedContainer[i];
		if (currentSpan > maxSpan)
			maxSpan = currentSpan;
	}
	std::cout << "=============== ============ ===============" << std::endl;
	return (maxSpan);
}
