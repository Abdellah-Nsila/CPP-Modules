#include <iostream>
#include "easyfind.hpp"

#include <algorithm>

int	main()
{
	typedef std::vector<int>		IntContainer;
	typedef IntContainer::iterator	IntIterator;

	IntContainer	container;
	IntIterator		it;
	
	container.push_back(0);
	container.push_back(2);
	container.push_back(3);


	it = std::find(container.begin(), container.end(), 2);
	if (it != container.end())
		std::cout << "Found" << std::endl;
	else
		std::cout << "Not Found" << std::endl;

	easyfind(container, 2);
	return 0;
}