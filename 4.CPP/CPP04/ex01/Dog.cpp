/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:14:12 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/07 21:37:25 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	_brain = new Brain();
	std::cout<<"Dog constructor called"<<std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout<<"Dog copy constructor called"<<std::endl;

}

Dog&	Dog::operator=(const Dog& other) {
	std::cout<<"Dog copy assignment operator called"<<std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog() {
	delete _brain;
	std::cout<<"Dog destructor called"<<std::endl;
}

void	Dog::makeSound() const {
	std::cout<<" Woof! Woof!"<<std::endl;
}
