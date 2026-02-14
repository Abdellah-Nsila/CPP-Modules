/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 08:38:56 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/14 08:38:57 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
