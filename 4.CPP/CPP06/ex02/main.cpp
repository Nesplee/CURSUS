/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +s#+           */
/*   Created: 2025/12/02 21:35:35 by dinguyen          #+#    #+#             */
/*   Updated: 2025/12/02 21:35:35 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base*	generate(void) {
	int	i = rand() % 3;
	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout<<"A"<<std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout<<"B"<<std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout<<"C"<<std::endl;
}

void	identify(Base& p) {
	try {
		A&	a = dynamic_cast<A&>(p);
		(void)a;
		std::cout<<"A"<<std::endl;
		return ;
	} catch (...) {}
	try {
		B&	b = dynamic_cast<B&>(p);
		(void)b;
		std::cout<<"B"<<std::endl;
		return ;
	} catch (...) {}
	try {
		C&	c = dynamic_cast<C&>(p);
		(void)c;
		std::cout<<"C"<<std::endl;
		return ;
	} catch (...) {}
}

int	main() {
	srand(time(0));
	Base*	ptr = generate();
	Base&	ref = *ptr;
	identify(ptr);
	identify(ref);
	delete ptr;
	return (0);
}
