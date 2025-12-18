template <typename T>
Array<T>::Array() : _size(0), _array(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (n > 0)
	{
		this->_array = new T[n];
		for (unsigned int i = 0; i < n; i++)
		{
			this->_array[i] = T();
		}
	}
	else
		this->_array = NULL;
}

template <typename T>
Array<T>::Array(const Array& copy) : _size(copy._size)
{
	if (copy._size > 0)
	{
		this->_array = new T[copy._size];
		for (unsigned int i = 0; i < copy._size; i++)
		{
			this->_array[i] = copy._array[i];
		}
	}
	else
		this->_array = NULL;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		delete[]	this->_array;
		this->_size = copy._size;
		if (copy._size > 0)
		{
			this->_array = new T[copy._size];
			for (unsigned int i = 0; i < copy._size; i++)
			{
				this->_array[i] = copy._array[i];
			}
		}
		else
			this->_array = NULL;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[]	this->_array;
}

template <typename T>
T&		Array<T>::operator[](unsigned int index)
{
	if (this->_size == 0 || index >= this->_size)
	{
		throw OutOfBoundsException();
	}
	return this->_array[index];
}

template <typename T>
const T&		Array<T>::operator[](unsigned int index) const
{
	if (this->_size == 0 || index >= this->_size)
	{
		throw OutOfBoundsException();
	}
	return this->_array[index];
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
const char*	Array<T>::OutOfBoundsException::what() const throw()
{
	return "Index out of bounds!";
}
