/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:18:29 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/12 10:49:10 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include "Harl.hpp"

using namespace std;

int main ()
{
    Harl    harl;

    harl.complain("Debug");
    harl.complain("Info");
    harl.complain("Warning");
    harl.complain("Error");
}
