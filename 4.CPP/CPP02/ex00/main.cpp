/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:14:49 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/18 10:54:56 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int	main()
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;
	Fixed	d;

	d = c = b;
	a.setRawBits(5);
	c = d = a;
	a = b;
	Fixed	e(d);
	std::cout<<a.getRawBits()<<std::endl;
	std::cout<<b.getRawBits()<<std::endl;
	std::cout<<c.getRawBits()<<std::endl;
	std::cout<<d.getRawBits()<<std::endl;
	std::cout<<e.getRawBits()<<std::endl;
	e.setRawBits(12);
	std::cout<<e.getRawBits()<<std::endl;
	return (0);
}
