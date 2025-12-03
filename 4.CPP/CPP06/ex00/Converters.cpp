/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:43:30 by dinguyen          #+#    #+#             */
/*   Updated: 2025/12/02 19:47:10 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static char 	_toChar(const std::string &literal);
static int		_toInt(const std::string &literal);
static float	_toFloat(const std::string &literal);
static double	_toDouble(const std::string &literal);

static char	_toChar(const std::string &literal) {
	ScalarConverter::ScalarType	type = detectType(literal);
	char	value;
	switch(type) {
		case ScalarConverter::T_CHAR:
			value = literal[1];
			break ;
		case ScalarConverter::T_INT:
			value = static_cast<char>(_toInt(literal));
			break ;
		case ScalarConverter::T_FLOAT:
			value = static_cast<char>(_toFloat(literal));
			break ;
		case ScalarConverter::T_DOUBLE:
			value = static_cast<char>(_toDouble(literal));
			break ;
		default:
			throw ScalarConverter::ConversionE();
	}
	if (!isprint(value))
		throw ScalarConverter::NonDisplayableE();
	return (value);
}

static int	_toInt(const std::string &literal) {
	ScalarConverter::ScalarType	type = detectType(literal);
	long	value;
	switch (type) {
		case ScalarConverter::T_INT:
			value = strtol(literal.c_str(), NULL, 10);
			break;
		case ScalarConverter::T_CHAR:
			value = static_cast<int>(literal[1]);
			break;
		case ScalarConverter::T_FLOAT:
			value = static_cast<long>(_toFloat(literal));
			break;
		case ScalarConverter::T_DOUBLE:
			value = static_cast<long>(_toDouble(literal));
			break;
		default:
			throw ScalarConverter::ConversionE();
	}
	if (value < INT_MIN)
		throw ScalarConverter::MinValueE();
	if (value > INT_MAX)
		throw ScalarConverter::MaxValueE();
	return (static_cast<int>(value));
}

static float	_toFloat(const std::string &literal) {
	ScalarConverter::ScalarType	type = detectType(literal);
	if (type == ScalarConverter::T_SPECIAL) {
		if (literal == "nanf") { return (NAN); }
		if (literal == "+inff") { return (INFINITY); }
		if (literal == "-inff") { return (-INFINITY); }
	}
	float	value;
	switch (type) {
		case ScalarConverter::T_FLOAT:
			value = strtof(literal.c_str(), NULL);
			break ;
		case ScalarConverter::T_INT:
			value = strtof(literal.c_str(), NULL);
			break ;
		case ScalarConverter::T_CHAR:
			value = static_cast<float>(literal[1]);
			break ;
		case ScalarConverter::T_DOUBLE:
			value = static_cast<float>(_toDouble(literal));
			break ;
		default:
			throw ScalarConverter::ConversionE();
	}
	if (value < FLOAT_LOW)
		throw	ScalarConverter::MinValueE();
	if (value > FLOAT_MAX)
		throw	ScalarConverter::MaxValueE();
	return (value);
}

static double	_toDouble(const std::string &literal) {
	ScalarConverter::ScalarType	type = detectType(literal);
	if (type == ScalarConverter::T_SPECIAL) {
		if (literal == "nan") { return (NAN); }
		if (literal == "+inf") { return (INFINITY); }
		if (literal == "-inf") { return (-INFINITY); }
	}
	double	value;
	switch (type) {
		case ScalarConverter::T_DOUBLE:
			value = strtod(literal.c_str(), NULL);
			break ;
		case ScalarConverter::T_INT:
			value = strtod(literal.c_str(), NULL);
			break ;
		case ScalarConverter::T_FLOAT:
			value = static_cast<double>(_toFloat(literal));
			break ;
		case ScalarConverter::T_CHAR:
			value = static_cast<double>(literal[1]);
			break ;
		default:
			throw ScalarConverter::ConversionE();
	}
	if (value < DOUBLE_LOW)
		throw ScalarConverter::MinValueE();
	if (value > DOUBLE_MAX)
		throw ScalarConverter::MaxValueE();
	return (value);
}

void	preConvert(const std::string &literal) {

	try {
		char c = _toChar(literal);
		std::cout<<"char: "<<c<<std::endl;
	} catch (ScalarConverter::NonDisplayableE &e) {
		std::cout<<"char: "<<e.what()<<std::endl;
	} catch (ScalarConverter::MaxValueE &e) {
		std::cout<<"char: "<<e.what()<<std::endl;
	} catch (ScalarConverter::MinValueE &e) {
		std::cout<<"char: "<<e.what()<<std::endl;
	} catch (ScalarConverter::ConversionE &e) {
		std::cout<<"char: "<<e.what()<<std::endl;
	}

	try {
		int	i = _toInt(literal);
		std::cout<<"int: "<<i<<std::endl;
	} catch (ScalarConverter::ConversionE &e) {
		std::cout<<"int: "<<e.what()<<std::endl;
	} catch (ScalarConverter::MinValueE &e) {
		std::cout<<"int: "<<e.what()<<std::endl;
	} catch (ScalarConverter::MaxValueE &e) {
		std::cout<<"int: "<<e.what()<<std::endl;
	}

	try {
		float f = _toFloat(literal);
		std::cout<<"float: "<<std::fixed<<std::setprecision(1)<<f<<"f"<<std::endl;
	} catch (ScalarConverter::ConversionE &e) {
		std::cout<<"float: "<<e.what()<<std::endl;
	} catch (ScalarConverter::MaxValueE &e) {
		std::cout<<"float: "<<e.what()<<std::endl;
	} catch (ScalarConverter::MinValueE &e) {
		std::cout<<"float: "<<e.what()<<std::endl;
	}
	try {
		double	d = _toDouble(literal);
		std::cout<<"double: "<<std::fixed<<std::setprecision(1)<<d<<std::endl;
	} catch (ScalarConverter::ConversionE &e) {
		std::cout<<"double: "<<e.what()<<std::endl;
	} catch (ScalarConverter::MinValueE &e) {
		std::cout<<"double: "<<e.what()<<std::endl;
	} catch (ScalarConverter::MaxValueE &e) {
		std::cout<<"double: "<<e.what()<<std::endl;
	}
}


