/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:07:37 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/16 12:22:21 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include <cctype>

#include <exception>
#include <stack>

enum operatorType
{
	PLUS,
	MINUS,
	MULTI,
	DIV,
	INVALID
};

int	RPN(const std::string& exp);
