#pragma once

#include <iostream>
#include <vector>

template <int N>
class Span
{
	private:
		std::vector<int>	container[N];
	public:
		Span();
		~Span();
};


