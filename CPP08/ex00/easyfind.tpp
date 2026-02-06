#include <vector>
#include <algorithm>

class NotFoundException : public std::exception
{
	public :
		const char*	what() const throw()
		{
			return "Element not found in container";
		}
};

template <typename T>
typename T::iterator	easyfind(T& container, int toFind)
{
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), toFind);
	if (it != container.end())
		return (it);
	throw NotFoundException();
}
