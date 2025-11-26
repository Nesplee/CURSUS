/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:59:25 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 11:17:47 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("") {
	std::cout<<"WrongAnimal defaut constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
	std::cout<<"WrongAnimal copy constructor called"<<std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout<<"WrongAnimal copy assignment operator called"<<std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout<<"WrongAnimal destructor called"<<std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout<<"*** SOME WRONGANIMAL NOISE***"<<std::endl;
}

std::string	WrongAnimal::getType() const {
	return (_type);
}
