/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:18:29 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/12 11:33:37 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

using namespace std;

int main (int argc, char *argv[])
{
	Harl    harl;
	
	if (argc != 2)
		return (1);

	harl.complain(argv[1]);
	return (0);
}
