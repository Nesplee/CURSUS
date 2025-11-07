/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:35:13 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/07 10:09:06 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawValue(0) {
	std::cout<<"Fixed constructor called"<<std::endl;
}

Fixed::~Fixed() {
	std::cout<<"Fixed destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& other) : _rawValue(other._rawValue) {
	std::cout<<"Fixed copy constructor called"<<std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout<<"Fixed copy assignment operator called"<<std::endl;
	if (this != &other) {
		this->_rawValue = other._rawValue;
	}
	return (*this);
}

//	PUBLICS METHODS
int	Fixed::getRawBits(void) const {
	std::cout<<"getRawBits member function called"<<std::endl;
	return (_rawValue);
}

void	Fixed::setRawBits(const int raw) {
	std::cout<<"setRawBits member function called"<<std::endl;
	_rawValue = raw;
}
