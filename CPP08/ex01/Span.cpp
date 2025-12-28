#include "Span.hpp"

Span::Span()
{
	this->container.reserve(0);
}

Span::Span(unsigned int N)
{
	this->container.reserve(N);
	for (unsigned int i; i < N; i++)
	{
		this->container[i] = 0;	
	}
}

Span::Span(Span& copy)
{

}

Span&	Span::operator=(Span& copy)
{

}

void	Span::addNumber(int number)
{
	this->container.emplace();
}

Span::~Span()
{
}