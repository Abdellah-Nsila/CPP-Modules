/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:07:00 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/04 09:07:01 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <stdlib.h>
#include <time.h>

template <typename T>
class Array
{
	private:
		unsigned int	_size;
		T*				_array;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);

		Array&			operator=(const Array& copy);
		T&				operator[](unsigned int index);
		const T&		operator[](unsigned int index) const;

		~Array();

		unsigned int	size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

#include "Array.tpp"
