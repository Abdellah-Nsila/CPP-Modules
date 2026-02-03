#include "Span.hpp"

Span::Span()
{
	this->_maxSize = 0;
	this->_container.reserve(0);
}

Span::Span(unsigned int N)
{
	this->_maxSize = N;
	this->_container.reserve(N);
	//
	for (unsigned int i = 0; i < N; i++)
	{
		this->_container[i] = 0;	
	}
}

Span::Span(Span& copy)
{
	this->_maxSize = copy._maxSize;
	this->_container.resize(copy._maxSize);
	for (unsigned int i = 0; i < copy._maxSize; i++)
	{
		this->_container[i] = copy._container[i];
	}
}

Span&	Span::operator=(Span& copy)
{
	if (this != &copy)
	{
		this->_maxSize = copy._maxSize;
		this->_container.resize(copy._maxSize);
		for (unsigned int i = 0; i < copy._maxSize; i++)
		{
			this->_container[i] = copy._container[i];
		}
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int number)
{
	if (this->_container.size() < this->_maxSize)
		this->_container.push_back(number);
	else
		std::cout << "Max Size reached!" << std::endl;
}

void	Span::display()
{
	for (unsigned int i = 0; i < this->_maxSize; i++)
	{
		std::cout << this->_container[i] << std::endl;
	}	
}
