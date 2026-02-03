#pragma once

#include <iostream>
#include <vector>

class Span
{
	private:
		std::vector<int>	_container;
	 	unsigned int		_maxSize;
	public:
		Span();
		Span(unsigned int N);
		Span(Span& copy);
		Span&	operator=(Span& copy);
		~Span();

		void	addNumber(int number);
		void	display();
	};
