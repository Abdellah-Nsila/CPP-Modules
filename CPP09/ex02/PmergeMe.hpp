/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:38 by abnsila           #+#    #+#             */
/*   Updated: 2026/03/01 13:57:08 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

std::vector<int>	jacobSequence(int groupsNum);
void	pmergeMe(std::vector<int>& numbers);

template <typename T>
void	displayContainer(T container)
{
	for (typename T::iterator it = container.begin(); it < container.end(); it++)
	{
		std::cout << *(it);
		if ((it + 1) != container.end())
			std::cout << " " << "\n";
	}
	std::cout << std::endl;
}
