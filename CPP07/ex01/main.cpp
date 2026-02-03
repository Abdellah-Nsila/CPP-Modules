/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:58:00 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/03 18:38:14 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void	print(T item)
{
	std::cout << item << std::endl;
}

int main()
{
	int						arr1[2] = {3, 10};
	const std::string		arr2[] = {"Hello", "World"};
	
	iter(arr1, 2, &print<int>);
	iter(arr2, 2, &print<std::string>);
}
