/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:45:56 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/06 09:39:36 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawValue(0) {
	std::cout<<"Fixed default constructor called"<<std::endl;
}

Fixed::Fixed(const int raw) : _rawValue(raw * (1 << _fractionnalBits)) {
	std::cout<<"Fixed int constructor called"<<std::endl;
}

Fixed::Fixed(const float raw) : _rawValue(static_cast<int>(roundf(raw * (1 << _fractionnalBits)))) {
	std::cout<<"Fixed float constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& other) : _rawValue(other._rawValue) {
	std::cout<<"Fixed copy constructor called"<<std::endl;
}

Fixed::~Fixed() {
	std::cout<<"Fixed destructor called"<<std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout<<"Fixed copy assignment operator called"<<std::endl;
	if (this != &other) {
		this->_rawValue = other._rawValue;
	}
	return (*this);
}

int	Fixed::getRawBits(void) const {
	return (_rawValue);
}

void	Fixed::setRawBits(const int raw) {
	_rawValue = raw;
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(_rawValue) / (1 << _fractionnalBits));
}

int		Fixed::toInt(void) const {
	return (_rawValue / (1 << _fractionnalBits));
}

std::ostream&	operator<<(std::ostream& os, const Fixed& obj) {
	os<<obj.toFloat();
	return(os);
}

