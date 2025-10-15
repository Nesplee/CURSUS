/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:22:24 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/07 21:35:40 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	_brain = new Brain();
	std::cout<<"Cat constructor called"<<std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout<<"Cat copy constructor called"<<std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout<<"Cat assigment operator called"<<std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat() {
	delete _brain;
	std::cout<<"Cat destructor called"<<std::endl;
}

void	Cat::makeSound() const {
	std::cout<<" Meow! Meow!"<<std::endl;
}
