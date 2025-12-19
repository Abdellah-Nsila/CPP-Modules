#include <vector>
#include <algorithm>

template <typename T>
void	easyfind(T& container, int toFind)
{
	(void)toFind;
	for(typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
