/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:26:41 by abnsila           #+#    #+#             */
/*   Updated: 2025/06/15 19:22:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

using namespace std;

int	ft_isdigit(int n)
{
	return (n >= 48 && n <= 57);
}

static int	handlemaxcase(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(string str)
{
	int				i;
	int					sign;
	unsigned long long	num;
	unsigned long long	max;

	i = 0;
	num = 0;
	sign = 1;
	max = 9223372036854775807;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && ft_isdigit((int)str[i]))
	{
		num = (num * 10) + (str[i] - 48);
		if (num >= max)
			return (handlemaxcase(sign));
		i++;
	}
	return ((int)(num * sign));
}

bool	isNumber(string str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
