#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& container, int toFind)
{
	typedef typename T::iterator	ContainerIterator;
	ContainerIterator	itFinded;

	for(ContainerIterator it = container.begin(); it != container.end(); it++)
	{
		itFinded = std::find(container.begin(), container.end(), toFind);
		if (itFinded != container.end())
			return (itFinded);
	}
	return (itFinded);
}
