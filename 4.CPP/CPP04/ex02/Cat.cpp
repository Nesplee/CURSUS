/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:57:51 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 16:57:32 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	_type = "Cat";
	_brain = new Brain();
	std::cout<<"Cat default constructor called"<<std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other) {
	std::cout<<"Cat copy constructor called"<<std::endl;
	_brain = new Brain(*other._brain);
}

Cat&	Cat::operator=(const Cat &other) {
	std::cout<<"Cat copy assignment operator called"<<std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
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
	std::cout<<" MEEEEEEOW! MMMEEEEOOWWWWW"<<std::endl;
}

void	Cat::setIdea(int index, const std::string &idea) {
	_brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index) const {
	std::string	result = _brain->getIdea(index);
	return (result);
}
