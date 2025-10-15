/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:24:10 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/07 21:46:57 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(const std::string &type) : _type(type) {
	std::cout<<"Animal constructor called"<<std::endl;
}

Animal::Animal(const Animal& other) {
	_type = other._type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "Animal assignment operator called" << std::endl;
	return (*this);
}

Animal::Animal() {
	std::cout<<"Animal constructor called"<<std::endl;
}

Animal::~Animal() {
	std::cout<<"Animal destructor called"<<std::endl;
}

void	Animal::makeSound() const {
	std::cout<<"* unknown animal sound *"<<std::endl;
}

std::string	Animal::getType() const { return (_type); }
