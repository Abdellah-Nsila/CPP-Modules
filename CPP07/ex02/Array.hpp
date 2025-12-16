#pragma once

#include <iostream>
#include <exception>

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

		Array&			operator=(const Array& copy);
		T&				operator[](unsigned int index);
		const T&		operator[](unsigned int index) const;

		~Array();

		class OutOfBoundsException : public std::exception
		{
			public:
				const char*	what() const throw();
		};		
};
