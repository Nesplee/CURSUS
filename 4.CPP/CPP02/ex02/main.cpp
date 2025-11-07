/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:28:03 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/07 10:05:59 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	Fixed	a;
	a.setRawBits(500);
	Fixed	b(22);
	Fixed	c(33.33f);
	const Fixed	d(5.2f), e(3.2f), f(99.9f);
	Fixed	m(5), n(8);
	Fixed	p(5.55f), q(72.128f);
	Fixed	z(0);

	std::cout<<std::endl;
	std::cout<<" ============================================================ "<<std::endl;
	std::cout<<"                     ARITHMETICS TESTS"<<std::endl;
	std::cout<<" ============================================================ "<<std::endl;
	std::cout<<std::endl;
	std::cout<<" a("<<a<<") + b("<<b<<") = "<<(a + b)<<std::endl;
	std::cout<<" b("<<b<<") - a("<<a<<") = "<<(b - a)<<std::endl;
	std::cout<<" c("<<c<<") * a("<<a<<") = "<<(c * a)<<std::endl;
	std::cout<<" c("<<c<<") / a("<<a<<") = "<<(c / a)<<std::endl;
	std::cout<<" ======== TESTS DIVISION BY 0 ======== "<<std::endl;
	std::cout<<" c("<<c<<") / z("<<z<<") = "<<(c / z)<<std::endl;
	std::cout<<" z("<<z<<") / c("<<c<<") = "<<(z / c)<<std::endl;
	std::cout<<std::endl;
	std::cout<<" ============================================================ "<<std::endl;
	std::cout<<"                      BOOLEANS TESTS"<<std::endl;
	std::cout<<" ============================================================ "<<std::endl;
	std::cout<<std::endl;
	std::cout<<" TEST WITH "<<m<<" AND "<<n<<std::endl;
	std::cout<<" is "<<m<<" < "<<n<<" ? "<<(m < n)<<std::endl;
	std::cout<<" is "<<m<<" <= "<<n<<" ? "<<(m <= n)<<std::endl;
	std::cout<<" is "<<m<<" > "<<n<<" ? "<<(m > n)<<std::endl;
	std::cout<<" is "<<m<<" >= "<<n<<" ? "<<(m >= n)<<std::endl;
	std::cout<<" is "<<m<<" == "<<n<<" ? "<<(m == n)<<std::endl;
	std::cout<<" is "<<m<<" != "<<n<<" ? "<<(m != n)<<std::endl;
	std::cout<<std::endl;
	std::cout<<" ============================================================ "<<std::endl;
	std::cout<<"           INCREMENTATION & DECREMENTATION TESTS"<<std::endl;
	std::cout<<" ============================================================ "<<std::endl;
	std::cout<<std::endl;
	std::cout<<" TEST PRE : "<<std::endl;
	std::cout<<" TEST WITH "<<p<<" AND "<<q<<std::endl;
		for (int i = 0; i < 3; i++) {
			std::cout<<" ++P returns: "<<++p<<" (P is now "<<p<<")"<<std::endl;
			std::cout<<" --Q returns: "<<--q<<" (Q is now "<<q<<")"<<std::endl;
			std::cout<<std::endl;
		}
	std::cout<<" TEST POST : "<<std::endl;
	std::cout<<" TEST WITH "<<p<<" AND "<<q<<std::endl;
		for (int i = 0; i < 3; i++) {
			std::cout<<" P++ returns: "<<p++<<" (but P is now "<<p<<")"<<std::endl;
			std::cout<<" Q-- returns: "<<q--<<" (but Q is now "<<q<<")"<<std::endl;
			std::cout<<std::endl;
		}
	std::cout<<std::endl;
	std::cout<<" ============================================================ "<<std::endl;
	std::cout<<"                      MIN & MAX TESTS"<<std::endl;
	std::cout<<" ============================================================ "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Smaller between a & b ["<<a<<"] & ["<<b<<"] : "<<std::endl;
	Fixed&	smaller = Fixed::min(a, b);
	std::cout<<"Smaller : "<<smaller<<std::endl;
	std::cout<<"Bigger between a & c ["<<a<<"] & ["<<c<<"] : "<<std::endl;
	Fixed&	bigger = Fixed::max(a, c);
	std::cout<<"Bigger : "<<bigger<<std::endl;
	std::cout<<"Const Smaller between d & e ["<<d<<"] & ["<<e<<"] : "<<std::endl;
	const Fixed& constSmaller = Fixed::min(d, e);
	std::cout<<"Const smaller : "<<constSmaller<<std::endl;
	std::cout<<"Const bigger between e & f ["<<e<<"] & ["<<f<<"] : "<<std::endl;
	const Fixed& constBigger = Fixed::max(e, f);
	std::cout<<"Const bigger : "<<constBigger<<std::endl;

	return (0);
}
