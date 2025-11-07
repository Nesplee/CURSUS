/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:22:37 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/07 11:15:50 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

class	Point
{

public:
	Point();
	~Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point&	operator=(const Point &other);
	const Fixed& getAttributeX() const;
	const Fixed& getAttributeY() const;

private:
	Fixed const	_attributeX;
	Fixed const	_attributeY;
};

Fixed	area(Point const& a, Point const& b, Point const& c);
bool	 bsp(Point const a, Point const b, Point const c, Point const point);

#endif
