/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:23:10 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/07 11:11:06 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.hpp"

//	OCF FUNCTIONS MEMBERS
Point::Point() : _attributeX(0), _attributeY(0) {
	std::cout<<"Point constructor called"<<std::endl;
}

Point::Point(const float x, const float y) : _attributeX(x), _attributeY(y) {
	std::cout<<"Point float parameters constructor called"<<std::endl;
}

Point::Point(const Point &other) : _attributeX(other._attributeX), _attributeY(other._attributeY) {
	std::cout<<"Point copy constructor called"<<std::endl;
}

Point&	Point::operator=(const Point &other) {
	std::cout<<"Point copy operator assignment called"<<std::endl;
	(void)other;
	return (*this);
}

Point::~Point() {
	std::cout<<"Point destructor called"<<std::endl;
}

//	GETTERS
const Fixed& Point::getAttributeX() const { return (_attributeX); }
const Fixed& Point::getAttributeY() const { return (_attributeY); }
