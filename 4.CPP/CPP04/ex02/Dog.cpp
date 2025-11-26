/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:29:28 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 17:00:27 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	_type = "Dog";
	_brain = new Brain();
	std::cout<<"Dog default constructor called"<<std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other) {
	std::cout<<"Dog copy constructor called"<<std::endl;
	_brain = new Brain(*other._brain);
}

Dog&	Dog::operator=(const Dog &other) {
	std::cout<<"Dog copy assignment operator called"<<std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
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
	std::cout<<"WOOOF!WOOOFFFFFFF! GRRRRRRRR"<<std::endl;
}

void	Dog::setIdea(int index, const std::string &idea) {
	_brain->setIdea(index, idea);
}

std::string	Dog::getIdea(int index) const {
	std::string idea = _brain->getIdea(index);
	return (idea);
}
