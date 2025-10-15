/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:55:28 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/18 16:01:05 by dinguyen         ###   ########.fr       */
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
	bool	operator<(const Fixed& other) const;
	bool	operator>(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;
	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);
	static	Fixed&			min(Fixed& a, Fixed& b);
	static	const Fixed&	min(const Fixed& a, const Fixed& b);
	static	Fixed&			max(Fixed& a, Fixed& b);
	static	const Fixed&	max(const Fixed& a, const Fixed& b);
private:
	static const int	_fractionnalBits = 8;
	int					_rawValue;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
