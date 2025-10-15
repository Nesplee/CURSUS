/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:55:08 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/19 10:59:50 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "point.hpp"

int	main()
{
	Point	a(0.0f, 0.0f);
	Point	b(5.0f, 0.0f);
	Point	c(2.5f, 5.0f);

	Point	in(2.5f, 2.0f);
	Point	out(5.0f, 5.0f);
	Point	edge(2.5f, 0.0f);
	Point	vertex(0.0f, 0.0f);

	std::cout<<"inside    : "<<bsp(a, b, c, in)<<std::endl;
	std::cout<<"outside   : "<<bsp(a, b, c, out)<<std::endl;
	std::cout<<"edge      : "<<bsp(a, b, c, edge)<<std::endl;
	std::cout<<"vertex    : "<<bsp(a, b, c, vertex)<<std::endl;
	return (0);
}
