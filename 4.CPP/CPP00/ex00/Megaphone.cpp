/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:45:03 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/13 13:57:00 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Megaphone.hpp"

Megaphone::Megaphone() {
	std::cout<<"Megaphone default constructor called"<<std::endl;
}

Megaphone::~Megaphone() {
	std::cout<<"Megaphone destructor called"<<std::endl;
}

std::string	Megaphone::toUpperCase(const std::string &text) {
	std::string	result = text;
	for (int i = 0; i < (int)result.length(); i++) {
		result[i] = std::toupper(result[i]);
	}
	return (result);
}
