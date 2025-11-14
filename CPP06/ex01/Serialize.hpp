/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:54:49 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/14 16:00:36 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>

typedef struct Data
{
	void	*content;
};

class Serialize
{
	public:
		Serialize(Serialize& copy);
		Serialize&	operator=(Serialize& copy);
		~Serialize();
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	private:
		Serialize(/* args */);
};

