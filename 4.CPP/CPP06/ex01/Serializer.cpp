/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:04:29 by dinguyen          #+#    #+#             */
/*   Updated: 2025/12/02 20:13:06 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &other) {
	*this = other;
}
Serializer&	Serializer::operator=(const Serializer &other) {
	(void)other;
	return (*this);
}
Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data* ptr) {
	uintptr_t	p = reinterpret_cast<uintptr_t>(ptr);
	return (p);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	Data*	p = reinterpret_cast<Data*>(raw);
	return (p);
}
