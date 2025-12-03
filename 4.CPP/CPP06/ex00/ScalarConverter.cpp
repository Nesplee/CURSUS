/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:40:46 by dinguyen          #+#    #+#             */
/*   Updated: 2025/12/03 10:40:42 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

const char*	ScalarConverter::ConversionE::what() const throw() {
	const char*	result = "Impossible";
	return (result);
}

const char*	ScalarConverter::MaxValueE::what() const throw() {
	const char*	result ="Value too high!";
	return (result);
}

const char*	ScalarConverter::MinValueE::what() const throw() {
	const char*	result = "Value too low!";
	return (result);
}

const char*	ScalarConverter::NonDisplayableE::what() const throw() {
	const char*	result = "Non displayable!";
	return (result);
}

void	ScalarConverter::convert(const std::string &literal) {
	preConvert(literal);
}

