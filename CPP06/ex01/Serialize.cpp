/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:54:39 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/14 16:03:21 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"


Serialize::Serialize(/* args */)
{
}


Serialize::Serialize(Serialize& copy)
{
	(void)copy;
}

Serialize&	Serialize::operator=(Serialize& copy)
{
	(void)copy;
	return (*this);
}

Serialize::~Serialize()
{
}

static uintptr_t	serialize(Data* ptr)
{
	return (static_cast<uintptr_t>(ptr));
}

static Data*		deserialize(uintptr_t raw)
{
	return (static_cast<Data*>(raw));
}

