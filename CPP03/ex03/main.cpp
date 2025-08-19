/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:37:07 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/17 14:34:06 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

using namespace std;

int main()
{
	FragTrap A("Alpha");

	A.attack("Enemy1");

	A.highFivesGuys();

	FragTrap B(A);

	FragTrap C("Charlie");
	C = A;

	return 0;
}
