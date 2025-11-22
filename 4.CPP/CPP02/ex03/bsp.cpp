/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:24:39 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/10 16:07:33 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "point.hpp"

Fixed	area(Point const& a, Point const& b, Point const& c) {
	Fixed	term1 = a.getAttributeX() * (b.getAttributeY() - c.getAttributeY());
	Fixed	term2 = b.getAttributeX() * (c.getAttributeY() - a.getAttributeY());
	Fixed	term3 = c.getAttributeX() * (a.getAttributeY() - b.getAttributeY());
	Fixed	result = (term1 + term2 + term3) / Fixed(2);
	if (result < Fixed(0))
		return (result * Fixed(-1));
	return (result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	areaABC = area(a, b, c);
	Fixed	areaPAB = area(point, a, b);
	Fixed	areaPBC = area(point, b, c);
	Fixed	areaPCA = area(point, c, a);

	if (areaPAB > Fixed(0) && areaPBC > Fixed(0) && areaPCA > Fixed(0)
		&& (areaPAB + areaPBC + areaPCA == areaABC))
		return (true);
	else
		return (false);
}
