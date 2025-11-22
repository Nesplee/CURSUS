/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:02:22 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/07 11:23:46 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout<<"Fixed default constructor called"<<std::endl;
}


Fixed::Fixed(const int value) : _fixedPointValue(value * (1 << _fractionnalBits)) {
	std::cout<<"Fixed int constructor called"<<std::endl;
}

Fixed::Fixed(const float value) : _fixedPointValue(static_cast<int>(roundf(value * (1 << _fractionnalBits)))) {
	std::cout<<"Fixed float constructor called"<<std::endl;

}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue) {
	std::cout<<"Fixed copy constructor called"<<std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout<<"Fixed copy assignment operator called"<<std::endl;
	if (this != &other) {
		_fixedPointValue = other._fixedPointValue;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const Fixed& f) {
	out<<f.toFloat();
	return (out);
}

Fixed::~Fixed() {
	std::cout<<"Fixed destructor called"<<std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout<<"getRawBits member function called"<<std::endl;
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const {
	float	value;
	value = static_cast<float>(_fixedPointValue) / (1 << _fractionnalBits);
	return (value);
}

int	Fixed::toInt(void) const {
	int		value;
	value = _fixedPointValue / (1 << _fractionnalBits);
	return (value);
}

bool	Fixed::operator>(const Fixed& other) const {
	if (this->_fixedPointValue > other._fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& other) const {
	if (this->_fixedPointValue < other._fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& other) const {
	if (this->_fixedPointValue >= other._fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& other) const {
	if (this->_fixedPointValue <= other._fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& other) const {
	if (this->_fixedPointValue == other._fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& other) const {
	if (this->_fixedPointValue != other._fixedPointValue)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed	result;
	result._fixedPointValue = this->_fixedPointValue + other._fixedPointValue;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const{
	Fixed	result;
	result._fixedPointValue = this->_fixedPointValue - other._fixedPointValue;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed	result;
	result._fixedPointValue = (this->_fixedPointValue * other._fixedPointValue) / (1 << _fractionnalBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const {
	if (other._fixedPointValue == 0) {
		std::cout<<"Warning: Division by zero automatically returning 0."<<std::endl;
		return (Fixed(0));
	}
	Fixed	result;
	result._fixedPointValue = (this->_fixedPointValue * (1 << _fractionnalBits)) / other._fixedPointValue;
	return (result);
}

Fixed&	Fixed::operator++() {
	(*this)._fixedPointValue = (*this)._fixedPointValue + (1 << _fractionnalBits);
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	old = *this;
	(*this)._fixedPointValue = (*this)._fixedPointValue + (1 << _fractionnalBits);
	return (old);
}

Fixed&	Fixed::operator--() {
	(*this)._fixedPointValue = (*this)._fixedPointValue - (1 << _fractionnalBits);
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	old = *this;
	(*this)._fixedPointValue = (*this)._fixedPointValue - (1 << _fractionnalBits);
	return (old);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return(a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return (a);
	else
		return(b);
}
