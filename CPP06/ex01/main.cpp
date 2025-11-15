/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:28:07 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/15 16:01:24 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include <iostream>

int	main()
{
	Data	*ptr1 = new Data();
	ptr1->id = 42;

	uintptr_t	raw = Serialize::serialize(ptr1);
	Data*		ptr2 = Serialize::deserialize(raw);

	std::cout << "ptr1: " << ptr1 << std::endl;
	std::cout << "ptr2: " << ptr2 << std::endl;

	std::cout << "Is Equals: " << (ptr1 == ptr2 ? "True" : "false") << std::endl;

	delete ptr1;
}
