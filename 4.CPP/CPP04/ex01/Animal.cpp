/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:05:25 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 10:24:54 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("") {
	std::cout<<"Animal default constructor called"<<std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
	std::cout<<"Animal copy constructor called"<<std::endl;
}

Animal&	Animal::operator=(const Animal &other) {
	std::cout<<"Animal copy assignment constructor called"<<std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout<<"Animal destructor called"<<std::endl;
}

std::string	Animal::getType() const {
	return (_type);
}

void	Animal::makeSound() const {
	std::cout<<"*** ANIMAL NOISE***"<<std::endl;
}
