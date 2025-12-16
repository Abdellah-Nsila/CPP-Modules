#include "Array.hpp"

template <typename T>
Array<T>::Array() : _n(0), _arr(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n), _arr(new T[n]) {}

template <typename T>
Array<T>::Array(const Array& copy)
{
	*this = copy;
}

//TODO: Issue in Syntax
template <typename T>
Array<T>&	Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		if (!copy._arr)
			return (*this);

		delete[]	this->_arr;
		this->_n = copy._n;
		this->_arr = new T[copy._n];

		for (unsigned int i = 0; i < copy._n; i++)
		{
			this->_arr[i] = copy._arr[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[]	this->_arr;
}

template <typename T>
T&		Array<T>::operator[](unsigned int index)
{
	if (this->_n == 0 || index < 0 || index >= this->_n)
	{
		throw OutOfBoundsException();
	}
	return this->_arr[index];
}

template <typename T>
const char*	Array<T>::OutOfBoundsException::what() const throw()
{
	return "Index out of bounds!";
}
