/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:00:41 by dinguyen          #+#    #+#             */
/*   Updated: 2025/12/02 18:43:15 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static const std::string _specialLiterals[6] = {
	"nan", "nanf", "+inf", "-inf", "+inff", "-inff"
};

static bool	_isChar(const std::string &literal) {
	if (literal.length() != 3)
		return (false);
	if (literal[0] != '\'' || literal[2] != '\'')
		return (false);
	if (!isprint(literal[2]))
		return (false);
	return (true);
}

static bool	_isInt(const std::string &literal) {
	if (literal.find('.') != std::string::npos)
		return (false);
	for (size_t i = 0; i < literal.length(); i++) {
		if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
			continue ;
		if (!isdigit(literal[i]))
			return (false);
	}
	return (true);
}

static bool	_isSpecialLiterals(const std::string &literal) {
	for (int i = 0; i < 6; i++) {
		if (_specialLiterals[i] == literal)
			return (true);
	}
	return (false);
}

static bool	_isFloat(const std::string &literal) {
	if (literal.length() < 2)
		return (false);
	if (literal[literal.length() - 1] != 'f')
		return (false);
	size_t	dot = literal.find('.');
	if (dot == std::string::npos)
		return (false);
	if (literal.find('.', dot + 1) != std::string::npos)
		return (false);
	for (size_t	i = 0; i < literal.length() - 1; i++) {
		if (i == dot)
			continue ;
		if ((literal[i] == '+' || literal[i] == '-') && i != 0)
			return (false);
		if (!isdigit(literal[i]) && literal[i] != '+' && literal[i] != '-')
			return (false);
	}
	return (true);
}

static bool	_isDouble(const std::string	&literal) {
	if (literal.length() < 2)
		return (false);
	if (literal.find('f') != std::string::npos)
		return (false);
	size_t	dot = literal.find('.');
	if (dot == std::string::npos)
		return (false);
	for (size_t	i = 0; i < literal.length(); i++) {
		if (i == dot)
			continue ;
		if ((literal[i] == '+' || literal[i] == '-') && i != 0)
			return (false);
		if (!isdigit(literal[i]) && literal[i] != '+' && literal[i] != '-')
			return (false);
	}
	return (true);
}

ScalarConverter::ScalarType	detectType(const std::string &literal) {
	if (_isChar(literal))
		return (ScalarConverter::T_CHAR);
	if (_isInt(literal))
		return (ScalarConverter::T_INT);
	if (_isFloat(literal))
		return (ScalarConverter::T_FLOAT);
	if (_isDouble(literal))
		return (ScalarConverter::T_DOUBLE);
	if (_isSpecialLiterals(literal))
		return (ScalarConverter::T_SPECIAL);
	return (ScalarConverter::T_INVALID);
}
