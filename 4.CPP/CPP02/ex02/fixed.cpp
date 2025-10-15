/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:55:31 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/18 16:04:54 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

//	C & D
Fixed::Fixed() : _rawValue(0) {
	std::cout<<"Fixed default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& other) : _rawValue(other._rawValue) {
	std::cout<<"Fixed copy constructor called"<<std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout<<"Fixed copy assignment operator called"<<std::endl;
	if (this != &other)
		this->_rawValue = other._rawValue;
	return (*this);
}

Fixed::~Fixed() {
	std::cout<<"Fixed destructor called"<<std::endl;
}

Fixed::Fixed(const int number) : _rawValue(number * 256) {
	std::cout<<"Fixed int constructor called"<<std::endl;
}

Fixed::Fixed(const float number) : _rawValue(static_cast<int>(roundf(number * 256))) {
	std::cout<<"Fixed float constructor called"<<std::endl;
}

float	Fixed::toFloat(void) const {
	return ((float)_rawValue / 256);
}

int		Fixed::toInt(void) const {
	return (_rawValue / 256);
}

//	POUR AFFICHER UN OBJET DE NOTRE CLASSE, ON DOIT CREER
//	LA FONCTION DE SURCHARGE D'OPERATEUR D'INSERTION,
//	POUR QUE C++ SACHE CE QU'IL FAUT AFFICHER QUAND ON std::cout<<OBJET.
//	LE PROTOTYPE DE CETTE FONCTION EST TOUJOURS LE MEME SUIVANT LES CLASSES

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os<<obj.toFloat();
	return (os);
}

//	PUBLICS METHODS
bool	Fixed::operator<(const Fixed& other) const {
	if (this->_rawValue < other._rawValue)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed& other) const {
	if (this->_rawValue > other._rawValue)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& other) const {
	if (this->_rawValue <= other._rawValue)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& other) const {
	if (this->_rawValue >= other._rawValue)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& other) const {
	if (this->_rawValue == other._rawValue)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& other) const {
	if (this->_rawValue != other._rawValue)
		return (true);
	return (false);
}

//	OPERATION FUNCTIONS
Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	result._rawValue = this->_rawValue + other._rawValue;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	result._rawValue = this->_rawValue - other._rawValue;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	result._rawValue = (this->_rawValue * other._rawValue) / 256;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	result._rawValue = (this->_rawValue * 256) / other._rawValue;
	return (result);
}

//	INCREMENTATION/DECREMENTATION
Fixed&	Fixed::operator++() {
	_rawValue = _rawValue + 1;
	return (*this);
}

Fixed&	Fixed::operator--() {
	_rawValue = _rawValue - 1;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
	_rawValue = _rawValue + 1;
	return (temp);
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	_rawValue = _rawValue - 1;
	return (temp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
