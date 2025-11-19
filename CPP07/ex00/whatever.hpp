/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:51:58 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/19 16:03:04 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void	swap(T& a, T& b)
{
	T	temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T		min(const T& a, const T& b)
{
	return (a < b ? a : b);
}

template <typename T>
T		max(const T& a, const T& b)
{
	return (a > b ? a : b);
}
