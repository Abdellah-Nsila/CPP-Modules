#include <iostream>
#include "easyfind.hpp"

int	main()
{
	std::vector<int> container;
	
	container.push_back(1);
	container.push_back(2);
	container.push_back(3);

	easyfind(container, 2);
	return 0;
}