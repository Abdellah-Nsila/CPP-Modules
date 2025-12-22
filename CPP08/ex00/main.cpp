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

	if (easyfind(container, 2) != container.end())
		std::cout << "Found" << std::endl;
	else
		std::cout << "Not Found" << std::endl;
	return 0;
}
