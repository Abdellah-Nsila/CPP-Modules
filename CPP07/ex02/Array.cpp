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

template <typename T>
Array&	Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		if (!copy._arr)
			return NULL;

		delete[]	this->_arr;
		this->_n = copy._n;
		this->_arr = new T[copy._n];

		for (unsigned int i = 0; i < copy.n; i++)
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
