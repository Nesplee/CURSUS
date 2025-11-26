/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:05:25 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 16:56:41 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() : _type("") {
	std::cout<<"AAnimal default constructor called"<<std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type) {
	std::cout<<"AAnimal copy constructor called"<<std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal &other) {
	std::cout<<"AAnimal copy assignment constructor called"<<std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout<<"AAnimal destructor called"<<std::endl;
}

std::string	AAnimal::getType() const {
	return (_type);
}

void	AAnimal::makeSound() const {
	std::cout<<"*** AAnimal NOISE***"<<std::endl;
}
