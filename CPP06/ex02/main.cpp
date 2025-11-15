/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:54:21 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/15 18:21:16 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main()
{
	srand(time(0));

	Base*	base1 = generate();
	identify(base1);
	identify(*base1);

	A*	a1 = new A();
	identify(a1);
	identify(*a1);

	B*	b1 = new B();
	identify(b1);
	identify(*b1);

	C*	c1 = new C();
	identify(c1);
	identify(*c1);

	delete base1;
	delete a1;
	delete b1;
	delete c1;
}
