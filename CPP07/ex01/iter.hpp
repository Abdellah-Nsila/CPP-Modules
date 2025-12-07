
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:57:58 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/24 18:28:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T, typename F>
void	iter(T* arr, const int n, F func)
{
	if (!arr || n <= 0)
		return;
	for (int i = 0; i < n; i++)
	{
		func(arr[i]);
	}
}

