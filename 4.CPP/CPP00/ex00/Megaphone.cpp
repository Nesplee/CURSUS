/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 09:14:12 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/06 09:22:22 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Megaphone.hpp"

Megaphone::Megaphone() {
	std::cout<<"Megaphone constructor called"<<std::endl;
}

Megaphone::~Megaphone() {
	std::cout<<"Megaphone destructor called"<<std::endl;
}

std::string	Megaphone::toUpperCase(const std::string &text) const {
	std::string result = text;
	size_t		i = 0;

	while (i < text.length()) {
		result[i] = std::toupper(result[i]);
		i++;
	}
	return (result);
}
