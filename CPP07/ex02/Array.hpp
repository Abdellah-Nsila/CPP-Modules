#pragma once

template <typename T>
class Array
{
	private:
		unsigned int	_n;
		T*				_arr;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array&	operator=(const Array& copy);
		~Array();
};
