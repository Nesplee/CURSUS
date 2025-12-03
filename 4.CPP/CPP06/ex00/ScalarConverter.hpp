/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:34:32 by dinguyen          #+#    #+#             */
/*   Updated: 2025/12/02 19:41:44 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cmath>
# include <limits>
# include <cstdlib>
# include <iomanip>

# define INT_MIN	std::numeric_limits<int>::min()
# define INT_MAX	std::numeric_limits<int>::max()
# define FLOAT_LOW	-(FLOAT_MAX)
# define FLOAT_MAX	std::numeric_limits<float>::max()
# define DOUBLE_LOW	-(DOUBLE_MAX)
# define DOUBLE_MAX	std::numeric_limits<double>::max()

class	ScalarConverter {

public:
	enum	ScalarType {
		T_INVALID,
		T_CHAR,
		T_INT,
		T_FLOAT,
		T_DOUBLE,
		T_SPECIAL
	};

	class	ConversionE : public std::exception {
		public:
			const char*	what() const throw();
	};

	class	MaxValueE : public std::exception {
		public:
			const char*	what() const throw();
	};

	class	MinValueE : public std::exception {
		public:
			const char*	what() const throw();
	};

	class NonDisplayableE : public std::exception {
		public:
			const char* what() const throw();
	};

	static void	convert(const std::string &literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter&	operator=(const ScalarConverter &other);
	~ScalarConverter();
};

ScalarConverter::ScalarType	detectType(const std::string &text);
void	preConvert(const std::string &literal);

#endif
