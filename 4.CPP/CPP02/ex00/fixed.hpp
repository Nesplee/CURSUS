/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:34:56 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/18 10:53:10 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class	Fixed
{

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(const int raw);

private:
	int					_rawValue;
	static const int	_fractionnalBits = 8;
};

#endif
