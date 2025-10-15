/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:03:41 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/18 11:57:49 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	Fixed(const int number);
	Fixed(const float number);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	static const int	_fractionnalBits = 8;
	int					_rawValue;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
