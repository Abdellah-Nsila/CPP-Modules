#pragma once

#include <iostream>
#include <vector>

// template <int N>
class Span
{
	private:
		std::vector<int>	container;
	public:
		Span();
		Span(unsigned int N);
		Span(Span& copy);
		Span&	operator=(Span& copy);
		~Span();

		void	addNumber(int number);
};
